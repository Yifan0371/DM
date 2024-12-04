// src/Equation.cpp
#include "Equation.h"

void Equation::compute_boundary_conditions(Variable& u_kp1) {
    int n = u_kp1.size();
    u_kp1[0] = 30.0;          // 左边界条件 T1 = 30
    u_kp1[n - 1] = 15.0;      // 右边界条件 T2 = 15
}

void Equation::compute_residual(const Variable& u, Variable& residual) {
    int n = u.size();
    for (int i = 1; i < n - 1; ++i) {
        residual[i] = u[i - 1] - 2 * u[i] + u[i + 1];
    }
    residual[0] = 0.0;
    residual[n - 1] = 0.0;
}


void Equation::compute_exact_solution(Variable& u_exact) {
    // 假设 T1 和 T2 是已知的边界条件
    double T1 = 30.0;
    double T2 = 15.0;

    IMesh* mesh = u_exact.getMesh();
    int n = u_exact.size();

    for (int i = 0; i < n; ++i) {
        double x = mesh->x_size(i);
        u_exact[i] = (T2 - T1) * x + T1;
    }
}


