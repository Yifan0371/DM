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
#include <execution>  // 新增并行执行策略头文件

template<typename Func>
concept InitialConditionFunction = requires(Func f, double x) {
    { f(x) } -> std::convertible_to<double>;
};

template<typename Solver>
concept IterativeSolver = requires(const Variable &u_k, Variable &u_kp1) {
    { Solver::compute_iteration(u_k, u_kp1) } -> std::same_as<void>;
};

class Equation {
public:
    template <InitialConditionFunction Func>
    void compute_initial_condition(Variable& u_k, Func init_func) {
        IMesh* mesh = u_k.getMesh();
        if (!mesh) {
            throw std::invalid_argument("Mesh pointer is null in compute_initial_condition.");
        }
        int size = u_k.size();
        std::vector<int> indices(size);
        std::iota(indices.begin(), indices.end(), 0);

        // 可以选择在这里使用并行执行策略（可选）
        std::transform(std::execution::par, indices.begin(), indices.end(), u_k.getValues().begin(),
                       [mesh, &init_func](int i) {
                           double x_i = mesh->x_size(i);
                           return init_func(x_i);
                       });
    }

    void compute_boundary_conditions(Variable& u_kp1);

    template <IterativeSolver Solver>
    void compute_for_solver(const Variable& u_k, Variable& u_kp1) {
        // 保持不变，此由Solver内部决定是否并行
        Solver::compute_iteration(u_k, u_kp1);
    }

    void compute_residual(const Variable& u, Variable& residual);
    void compute_exact_solution(Variable& u_exact);

private:
    static constexpr double T1 = 30.0;
    static constexpr double T2 = 15.0;
};

#endif // EQUATION_H
