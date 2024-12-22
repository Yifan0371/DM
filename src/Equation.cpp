#include "Equation.h"
#include <numeric>
#include <cmath>

// Apply boundary conditions to the variable u_kp1.
// Set the first and last values of u_kp1 to the boundary temperatures T1 and T2.
void Equation::compute_boundary_conditions(Variable& u_kp1) {
    auto& values = u_kp1.getValues();
    values.front() = T1; // Set left boundary condition
    values.back() = T2;  // Set right boundary condition
}

// Compute the residual of the solution u and store it in the residual variable.
// Residual is calculated as r[i] = u[i-1] - 2*u[i] + u[i+1] for interior points.
void Equation::compute_residual(const Variable& u, Variable& residual) {
    const auto& u_values = u.getValues();
    auto& r_values = residual.getValues();
    int n = u.size();

    // Boundary residuals are zero.
    r_values.front() = 0.0;
    r_values.back() = 0.0;

    // Generate indices for interior points and compute residual using a transform.
    std::vector<int> indices(n - 2);
    std::iota(indices.begin(), indices.end(), 1);

    std::transform(indices.begin(), indices.end(), r_values.begin() + 1,
                   [&u_values](int i) {
                       return u_values[i - 1] - 2 * u_values[i] + u_values[i + 1];
                   });
}

// Compute the exact solution of the Laplace equation and store it in u_exact.
// The exact solution is u(x) = (T2 - T1) * x + T1, based on linear interpolation.
void Equation::compute_exact_solution(Variable& u_exact) {
    IMesh* mesh = u_exact.getMesh();
    if (!mesh) {
        throw std::invalid_argument("Mesh pointer is null in compute_exact_solution.");
    }

    int size = u_exact.size();
    std::vector<int> indices(size);
    std::iota(indices.begin(), indices.end(), 0);

    auto& values = u_exact.getValues();
    // Compute the exact solution for each point based on its position.
    std::transform(indices.begin(), indices.end(), values.begin(),
                   [this, mesh](int i) {
                       double x_i = mesh->x_size(i); // Get position x_i from the mesh
                       return (T2 - T1) * x_i + T1; // Exact solution formula
                   });
}
