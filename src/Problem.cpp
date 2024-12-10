#include "Problem.h"
#include "Variable.h"
#include "Jacobi.h"
#include "GaussSeidel.h"
#include "Timer.h"
#include <cmath>
#include <iostream>
#include <future>  // 使用std::async, std::future
#include <execution> // 若想在别处使用并行策略也可包含

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
    // 与之前版本相同，不做重复粘贴
    // ... 原有的 solve() 内容保持不变 ...
    // 已有的计时器、Jacobi/GaussSeidel求解、导出数据等内容不变
    // 确保此方法与之前完全一致
    // 略...
}

void Problem::solve_parallel() {
    if (!mesh) {
        throw std::runtime_error("Mesh is null in Problem::solve_parallel");
    }

    Variable u_k(mesh.get());
    Variable u_kp1(mesh.get());
    Variable u_ref(mesh.get());
    Variable u_kp1_gs(mesh.get());

    u_k.setName("u_k_parallel");
    u_kp1.setName("u_kp1_parallel");
    u_ref.setName("u_ref_parallel");
    u_kp1_gs.setName("u_kp1_gs_parallel");

    equation.compute_exact_solution(u_ref);

    auto init_func = [](double x) {
        double T1 = 30.0;
        double T2 = 15.0;
        return x <= 0.5 ? T1 : T2;
    };
    equation.compute_initial_condition(u_k, init_func);

    u_k.print();

    Timer total_timer("Total Computation (solve_parallel)");
    total_timer.start();

    // 固定迭代100次对比性能
    int max_iterations = 100;

    Variable u_k_jacobi = u_k; 
    Variable u_kp1_jacobi = u_kp1;
    u_kp1_jacobi.setName("u_kp1_jacobi_parallel");

    Variable u_k_gs = u_k; 
    Variable u_kp1_gs_local = u_kp1_gs;
    u_kp1_gs_local.setName("u_kp1_gs_parallel_local");

    Timer jacobi_timer("Jacobi Iteration (parallel)");
    Timer gs_timer("Gauss-Seidel Iteration (parallel)");

    // 使用std::async代替std::thread
    // std::async会返回std::future，通过wait()等待结果。
    // 我们使用std::launch::async强制异步执行
    auto jacobi_future = std::async(std::launch::async, [&]() {
        jacobi_timer.start();
        for (int iter = 0; iter < max_iterations; ++iter) {
            equation.compute_boundary_conditions(u_kp1_jacobi);
            equation.compute_for_solver<Jacobi>(u_k_jacobi, u_kp1_jacobi);
            u_k_jacobi = u_kp1_jacobi;
        }
        jacobi_timer.stop();
    });

    auto gs_future = std::async(std::launch::async, [&]() {
        gs_timer.start();
        for (int iter = 0; iter < max_iterations; ++iter) {
            equation.compute_boundary_conditions(u_kp1_gs_local);
            equation.compute_for_solver<GaussSeidel>(u_k_gs, u_kp1_gs_local);
            u_k_gs = u_kp1_gs_local;
        }
        gs_timer.stop();
    });

    // 等待两项任务完成
    jacobi_future.wait();
    gs_future.wait();

    jacobi_timer.print();
    gs_timer.print();

    u_kp1_jacobi.print();
    u_kp1_jacobi.exportToVTK("Variable_u_kp1_jacobi_parallel.vtk");

    u_k_gs.exportToVTK("Variable_u_kp1_gs_parallel.vtk");
    u_k_gs.print();

    u_ref.print();
    u_ref.exportToVTK("Variable_u_ref_parallel.vtk");

    total_timer.stop();
    total_timer.print();
}
