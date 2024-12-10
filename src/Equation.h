// Equation.h
#ifndef EQUATION_H
#define EQUATION_H

#include "Variable.h"
#include "IMesh.h"
#include <numeric>
#include <concepts>
#include <type_traits>
#include <algorithm>
#include <functional>
#include <stdexcept>

// 初始条件函数概念：要求接收double返回double
template<typename Func>
concept InitialConditionFunction = requires(Func f, double x) {
    { f(x) } -> std::convertible_to<double>;
};

// 求解器概念：
// 要求Solver类有static void compute_iteration(const Variable&, Variable&)
template<typename Solver>
concept IterativeSolver = requires(const Variable &u_k, Variable &u_kp1) {
    { Solver::compute_iteration(u_k, u_kp1) } -> std::same_as<void>;
};

class Equation {
public:
    // 使用concept约束初始条件函数的模板方法
    template <InitialConditionFunction Func>
    void compute_initial_condition(Variable& u_k, Func init_func) {
        IMesh* mesh = u_k.getMesh();
        if (!mesh) {
            throw std::invalid_argument("Mesh pointer is null in compute_initial_condition.");
        }
        int size = u_k.size();
        std::vector<int> indices(size);
        std::iota(indices.begin(), indices.end(), 0);

        std::transform(indices.begin(), indices.end(), u_k.getValues().begin(),
                       [mesh, &init_func](int i) {
                           double x_i = mesh->x_size(i);
                           return init_func(x_i);
                       });
    }

    // 边界条件
    void compute_boundary_conditions(Variable& u_kp1);

    // 使用concept约束迭代求解器
    template <IterativeSolver Solver>
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
