// Equation.h
#ifndef EQUATION_H
#define EQUATION_H

#include "Variable.h"
#include "IMesh.h"
#include <concepts>
#include <type_traits>
#include <algorithm>
#include <functional>
#include <stdexcept>
#include <numeric>
#include <execution>

// Define a concept for functions used as initial conditions.
// These functions should take a double as input and return a double.
template<typename Func>
concept InitialConditionFunction = requires(Func f, double x) {
    { f(x) } -> std::convertible_to<double>;
};

// Define a concept for iterative solvers.
// These solvers must have a static method compute_iteration that operates on Variables.
template<typename Solver>
concept IterativeSolver = requires(const Variable &u_k, Variable &u_kp1) {
    { Solver::compute_iteration(u_k, u_kp1) } -> std::same_as<void>;
};

class Equation {
public:
    // Compute the initial condition of the variable u_k based on the provided function.
    template <InitialConditionFunction Func>
    void compute_initial_condition(Variable& u_k, Func init_func) {
        IMesh* mesh = u_k.getMesh();
        if (!mesh) {
            throw std::invalid_argument("Mesh pointer is null in compute_initial_condition.");
        }
        int size = u_k.size();
        std::vector<int> indices(size);
        std::iota(indices.begin(), indices.end(), 0);

        // Use parallel execution to compute initial values at each point in the mesh.
        std::transform(std::execution::par, indices.begin(), indices.end(), u_k.getValues().begin(),
                       [mesh, &init_func](int i) {
                           double x_i = mesh->x_size(i); // Get position x_i from the mesh
                           return init_func(x_i);        // Apply the initial condition function
                       });
    }

    // Apply boundary conditions to the variable u_kp1.
    void compute_boundary_conditions(Variable& u_kp1);

    // Compute the next iteration for the solver.
    // The solver must satisfy the IterativeSolver concept.
    template <IterativeSolver Solver>
    void compute_for_solver(const Variable& u_k, Variable& u_kp1) {
        Solver::compute_iteration(u_k, u_kp1);
    }

    // Compute the residual of the solution and store it in the residual variable.
    void compute_residual(const Variable& u, Variable& residual);

    // Compute the exact solution of the Laplace equation and store it in u_exact.
    void compute_exact_solution(Variable& u_exact);

private:
    // Constants representing the boundary temperatures.
    static constexpr double T1 = 30.0;
    static constexpr double T2 = 15.0;
};

#endif // EQUATION_H
