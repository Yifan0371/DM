#include "Problem.h"
#include "Variable.h"
#include "Jacobi.h"
#include "GaussSeidel.h"
#include "Timer.h"
#include <cmath>
#include <iostream>
#include <future>  
#include <execution> 

// Constructor: Initializes the Problem object with a given mesh
Problem::Problem(std::unique_ptr<IMesh> mesh) : mesh(std::move(mesh)) {}

// Function to check convergence based on the maximum difference between two iterations
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

// Function to solve the problem sequentially
void Problem::solve() {
    if (!mesh) {
        throw std::runtime_error("Mesh is null in Problem::solve");
    }

    // Initialize variables
    Variable u_k(mesh.get());
    Variable u_kp1(mesh.get());
    Variable u_ref(mesh.get());
    Variable u_kp1_gs(mesh.get());

    // Set names for the variables
    u_k.setName("u_k");
    u_kp1.setName("u_kp1");
    u_ref.setName("u_ref");
    u_kp1_gs.setName("u_kp1_gs");

    // Compute the exact solution
    equation.compute_exact_solution(u_ref);

    // Define initial condition function
    auto init_func = [](double x) {
        double T1 = 30.0;
        double T2 = 15.0;
        return x <= 0.5 ? T1 : T2;
    };
    equation.compute_initial_condition(u_k, init_func);

    // Print the initial condition
    u_k.print();

    // Timer for total computation
    Timer total_timer("Total Computation (solve)");
    total_timer.start();

    // Solve using the Jacobi method
    {
        Timer jacobi_timer("Jacobi Iteration");
        jacobi_timer.start();

        int iteration_count = 0;
        double epsilon = 1e-5;
        Variable u_k_jacobi = u_k;

        while (true) {
            equation.compute_boundary_conditions(u_kp1);
            equation.compute_for_solver<Jacobi>(u_k_jacobi, u_kp1);

            if (has_converged(u_k_jacobi, u_kp1, epsilon)) {
                break;
            }

            u_k_jacobi = u_kp1;
            iteration_count++;
        }

        jacobi_timer.stop();
        jacobi_timer.print();

        std::cout << "Jacobi method converged in " << iteration_count << " iterations." << std::endl;

        u_kp1.print();
        u_kp1.exportToVTK("Variable_u_kp1.vtk");
    }

    // Solve using the Gauss-Seidel method
    {
        Timer gs_timer("Gauss-Seidel Iteration");
        gs_timer.start();

        int iteration_count = 0;
        double epsilon = 1e-5;
        Variable u_k_gs = u_k;

        while (true) {
            equation.compute_boundary_conditions(u_kp1_gs);
            equation.compute_for_solver<GaussSeidel>(u_k_gs, u_kp1_gs);

            if (has_converged(u_k_gs, u_kp1_gs, epsilon)) {
                break;
            }

            u_k_gs = u_kp1_gs;
            iteration_count++;
        }

        gs_timer.stop();
        gs_timer.print();

        std::cout << "Gauss-Seidel method converged in " << iteration_count << " iterations." << std::endl;

        u_kp1_gs.print();
        u_kp1_gs.exportToVTK("Variable_u_kp1_gs.vtk");
    }

    // Export and print the exact solution
    u_ref.print();
    u_ref.exportToVTK("Variable_u_ref.vtk");

    total_timer.stop();
    total_timer.print();
}

// Function to solve the problem in parallel
void Problem::solve_parallel() {
    if (!mesh) {
        throw std::runtime_error("Mesh is null in Problem::solve_parallel");
    }

    // Initialize variables
    Variable u_k(mesh.get());
    Variable u_kp1(mesh.get());
    Variable u_ref(mesh.get());
    Variable u_kp1_gs(mesh.get());

    // Set names for the variables
    u_k.setName("u_k_parallel");
    u_kp1.setName("u_kp1_parallel");
    u_ref.setName("u_ref_parallel");
    u_kp1_gs.setName("u_kp1_gs_parallel");

    // Compute the exact solution
    equation.compute_exact_solution(u_ref);

    // Define initial condition function
    auto init_func = [](double x) {
        double T1 = 30.0;
        double T2 = 15.0;
        return x <= 0.5 ? T1 : T2;
    };
    equation.compute_initial_condition(u_k, init_func);

    // Print the initial condition
    u_k.print();

    // Timer for total computation
    Timer total_timer("Total Computation (solve_parallel)");
    total_timer.start();

    // Set the maximum number of iterations
    int max_iterations = 100;

    Variable u_k_jacobi = u_k; 
    Variable u_kp1_jacobi = u_kp1;
    u_kp1_jacobi.setName("u_kp1_jacobi_parallel");

    Variable u_k_gs = u_k; 
    Variable u_kp1_gs_local = u_kp1_gs;
    u_kp1_gs_local.setName("u_kp1_gs_parallel_local");

    Timer jacobi_timer("Jacobi Iteration (parallel)");
    Timer gs_timer("Gauss-Seidel Iteration (parallel)");

    // Parallel execution of Jacobi and Gauss-Seidel methods
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

    // Wait for both computations to complete
    jacobi_future.wait();
    gs_future.wait();

    // Print timers
    jacobi_timer.print();
    gs_timer.print();

    // Export and print results
    u_kp1_jacobi.print();
    u_kp1_jacobi.exportToVTK("Variable_u_kp1_jacobi_parallel.vtk");

    u_k_gs.exportToVTK("Variable_u_kp1_gs_parallel.vtk");
    u_k_gs.print();

    u_ref.print();
    u_ref.exportToVTK("Variable_u_ref_parallel.vtk");

    total_timer.stop();
    total_timer.print();
}
