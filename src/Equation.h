// src/Equation.h
#ifndef EQUATION_H
#define EQUATION_H

#include "Variable.h"
#include <functional>
#include <concepts>
#include <cmath>

template <typename Func>
concept InitialConditionFunc = requires(Func f, double x) {
    { f(x) } -> std::convertible_to<double>;
};

class Equation {
public:
    // 初始条件
    template <InitialConditionFunc Func>
    void compute_initial_condition(Variable& u_k, Func init_func) {
        int n = u_k.size();
        IMesh* mesh = u_k.getMesh();
        for (int i = 0; i < n; ++i) {
            double x_i = mesh->x_size(i);
            u_k[i] = init_func(x_i);
        }
    }

    void compute_boundary_conditions(Variable& u_kp1);

    // 求解器
    template <typename Solver>
    requires requires(const Variable& u_k, Variable& u_kp1) {
        { Solver::compute_iteration(u_k, u_kp1) } -> std::same_as<void>;
    }
    void compute_for_solver(const Variable& u_k, Variable& u_kp1) {
        Solver::compute_iteration(u_k, u_kp1);
    }

    void compute_residual(const Variable& u, Variable& residual);
    void compute_exact_solution(Variable& u_exact);
};

#endif // EQUATION_H
