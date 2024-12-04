// Problem.cpp
#include "Problem.h"
#include "Jacobi.h"
#include "GaussSeidel.h"
#include <cmath>
#include <iostream>

Problem::Problem(std::unique_ptr<IMesh> mesh) : mesh(std::move(mesh)) {}

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

void Problem::solve() {
    if (!mesh) {
        throw std::runtime_error("Mesh is null in Problem::solve");
    }

    // 初始化变量
    Variable u_k(mesh.get());
    Variable u_kp1(mesh.get());
    Variable u_ref(mesh.get());
    Variable u_kp1_gs(mesh.get());

    u_k.setName("u_k");
    u_kp1.setName("u_kp1");
    u_ref.setName("u_ref");
    u_kp1_gs.setName("u_kp1_gs");

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

    // Jacobi 方法迭代求解
    {
        int iteration_count = 0;
        double epsilon = 1e-5;
        Variable u_k_jacobi = u_k; // 保存初始条件

        while (true) {
            equation.compute_boundary_conditions(u_kp1);
            equation.compute_for_solver<Jacobi>(u_k_jacobi, u_kp1);

            if (has_converged(u_k_jacobi, u_kp1, epsilon)) {
                break;
            }

            u_k_jacobi = u_kp1;
            iteration_count++;
        }

        std::cout << "Jacobi method converged in " << iteration_count << " iterations." << std::endl;

        // 导出数值解
        u_kp1.print();
        u_kp1.exportToVTK("Variable_u_kp1.vtk");
    }

    // Gauss-Seidel 方法迭代求解
    {
        int iteration_count = 0;
        double epsilon = 1e-5;
        Variable u_k_gs = u_k; // 保存初始条件

        while (true) {
            equation.compute_boundary_conditions(u_kp1_gs);
            equation.compute_for_solver<GaussSeidel>(u_k_gs, u_kp1_gs);

            if (has_converged(u_k_gs, u_kp1_gs, epsilon)) {
                break;
            }

            u_k_gs = u_kp1_gs;
            iteration_count++;
        }

        std::cout << "Gauss-Seidel method converged in " << iteration_count << " iterations." << std::endl;

        // 导出数值解
        u_kp1_gs.print();
        u_kp1_gs.exportToVTK("Variable_u_kp1_gs.vtk");
    }

    // 导出精确解
    u_ref.print();
    u_ref.exportToVTK("Variable_u_ref.vtk");
}
