// src/Problem.cpp
#include "Problem.h"
#include "Jacobi.h"
#include "GaussSeidel.h"
#include <iostream>
#include <cmath>
#include <stdexcept>

Problem::Problem(std::unique_ptr<IMesh> mesh) : mesh(std::move(mesh)) {}

Problem::~Problem() {}

bool Problem::has_converged(const Variable& u_k, const Variable& u_kp1, double epsilon) const {
    double max_diff = 0.0;
    int n = u_k.size();

    for (int i = 0; i < n; ++i) {
        double diff = std::abs(u_kp1[i] - u_k[i]);
        if (diff > max_diff) {
            max_diff = diff;
        }
    }

    return max_diff < epsilon;
}

// Problem.cpp
void Problem::solve() {
    if (!mesh) {
        throw std::runtime_error("Mesh is null in Problem::solve");
    }

    // 初始化变量
    Variable u_k(mesh.get());
    Variable u_kp1(mesh.get());
    Variable u_ref(mesh.get());

    u_k.setName("u_k");
    u_kp1.setName("u_kp1");
    u_ref.setName("u_ref");

    // 计算精确解
    equation.compute_exact_solution(u_ref);

    // 设置初始条件
    auto init_func = [](double x) {
        double T1 = 30.0;
        double T2 = 15.0;
        return x <= 0.5 ? T1 : T2;
    };
    equation.compute_initial_condition(u_k, init_func);

    // 导出初始条件
    u_k.print();

    // 迭代求解过程
    int iteration_count = 0;
    double epsilon = 1e-5;

    while (true) {
        equation.compute_boundary_conditions(u_kp1);
        equation.compute_for_solver<Jacobi>(u_k, u_kp1);

        if (has_converged(u_k, u_kp1, epsilon)) {
            break;
        }

        u_k = u_kp1;
        iteration_count++;
    }

    std::cout << "Jacobi method converged in " << iteration_count << " iterations." << std::endl;

    // 计算残差
    Variable residual(mesh.get());
    equation.compute_residual(u_kp1, residual);

    // 计算残差的无穷范数
    double max_residual = 0.0;
    for (int i = 0; i < residual.size(); ++i) {
        double res = std::abs(residual[i]);
        if (res > max_residual) {
            max_residual = res;
        }
    }

    std::cout << "Maximum residual: " << max_residual << std::endl;

    // 导出数值解和精确解
    u_kp1.print();
    u_ref.print();
}
