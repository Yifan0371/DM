// Equation.cpp
#include "Equation.h"

void Equation::compute_boundary_conditions(Variable& u_kp1) {
    auto& values = u_kp1.getValues();
    values.front() = T1;
    values.back() = T2;
}

void Equation::compute_residual(const Variable& u, Variable& residual) {
    const auto& u_values = u.getValues();
    auto& residual_values = residual.getValues();
    int n = u.size();

    residual_values.front() = 0.0;
    residual_values.back() = 0.0;

    for (int i = 1; i < n - 1; ++i) {
        residual_values[i] = u_values[i - 1] - 2 * u_values[i] + u_values[i + 1];
    }
}

void Equation::compute_exact_solution(Variable& u_exact) {
    IMesh* mesh = u_exact.getMesh();
    if (!mesh) {
        throw std::invalid_argument("Mesh pointer is null in compute_exact_solution.");
    }

    int size = u_exact.size();
    for (int i = 0; i < size; ++i) {
        double x_i = mesh->x_size(i);
        u_exact[i] = (T2 - T1) * x_i + T1;
    }
}
