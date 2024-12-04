#include "Problem.h"
#include <iostream>
#include <cmath>

Problem::Problem(std::unique_ptr<IMesh> mesh) : mesh(std::move(mesh)), iterationCount(0) {}

Problem::~Problem() {
    // 不需要手动删除 mesh，unique_ptr 会自动管理
}

bool Problem::has_converged(Variable& u_k, Variable& u_kp1, double epsilon) const {
    double max_diff = 0.0;
    int n = u_k.size();

    // 计算无穷范数
    for (int i = 0; i < n; ++i) {
        double diff = std::abs(u_kp1[i] - u_k[i]);
        if (diff > max_diff) {
            max_diff = diff;
        }
    }

    return max_diff < epsilon;
}

void Problem::solve() {
    std::cout << "--- Solve problem ---" << std::endl;

    // 初始化变量
    Variable u_k(mesh.get());     // 当前解
    Variable u_kp1(mesh.get());   // 下一步解

    // 设置初始条件
    equation.compute_initial_condition(u_k, mesh.get());

    // 迭代求解
    int iteration_count = 0;
    double epsilon = 1e-5; // 收敛阈值

    while (true) {
        // 设置边界条件
        equation.compute_boundary_conditions(u_kp1, mesh.get());

        // 计算下一步解
        equation.compute(u_k, u_kp1, mesh.get());

        // 检查是否收敛
        if (has_converged(u_k, u_kp1, epsilon)) {
            break;
        }

        // 将 u_kp1 复制到 u_k，为下一次迭代准备
        u_k = u_kp1;

        // 记录迭代次数并输出进展
        iteration_count++;
    }

    std::cout << "Solution completed after " << iteration_count << " iterations." << std::endl;
}
