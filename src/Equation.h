// Equation.h
#ifndef EQUATION_H
#define EQUATION_H

#include "Variable.h"
#include <type_traits>
#include <algorithm>
#include <functional>
#include <stdexcept>

class Equation {
public:
    // 初始条件函数
    template <typename Func>
    void compute_initial_condition(Variable& u_k, Func init_func) {
        static_assert(std::is_invocable_r<double, Func, double>::value,
                      "init_func must be callable with double and return double");
        IMesh* mesh = u_k.getMesh();
        if (!mesh) {
            throw std::invalid_argument("Mesh pointer is null in compute_initial_condition.");
        }
        int size = u_k.size();
        for (int i = 0; i < size; ++i) {
            double x_i = mesh->x_size(i);
            u_k[i] = init_func(x_i);
        }
    }

    // 边界条件
    void compute_boundary_conditions(Variable& u_kp1);

    // 求解器接口
    template <typename Solver>
    void compute_for_solver(const Variable& u_k, Variable& u_kp1) {
        Solver::compute_iteration(u_k, u_kp1);
    }

    // 残差计算
    void compute_residual(const Variable& u, Variable& residual);

    // 计算精确解
    void compute_exact_solution(Variable& u_exact);

private:
    static constexpr double T1 = 30.0;
    static constexpr double T2 = 15.0;
};

#endif // EQUATION_H
