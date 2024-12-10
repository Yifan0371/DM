// Equation.cpp
#include "Equation.h"
#include <numeric>
#include <cmath>

void Equation::compute_boundary_conditions(Variable& u_kp1) {
    auto& values = u_kp1.getValues();
    values.front() = T1;
    values.back() = T2;
}

void Equation::compute_residual(const Variable& u, Variable& residual) {
    const auto& u_values = u.getValues();
    auto& r_values = residual.getValues();
    int n = u.size();

    r_values.front() = 0.0;
    r_values.back() = 0.0;

    std::vector<int> indices(n-2);
    std::iota(indices.begin(), indices.end(), 1);

    std::transform(indices.begin(), indices.end(), r_values.begin()+1,
                   [&u_values](int i) {
                       return u_values[i - 1] - 2 * u_values[i] + u_values[i + 1];
                   });
}

void Equation::compute_exact_solution(Variable& u_exact) {
    IMesh* mesh = u_exact.getMesh();
    if (!mesh) {
        throw std::invalid_argument("Mesh pointer is null in compute_exact_solution.");
    }

    int size = u_exact.size();
    std::vector<int> indices(size);
    std::iota(indices.begin(), indices.end(), 0);

    auto& values = u_exact.getValues();
    std::transform(indices.begin(), indices.end(), values.begin(),
                   [this, mesh](int i) {
                       double x_i = mesh->x_size(i);
                       return (T2 - T1)*x_i + T1;
                   });
}
