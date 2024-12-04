// GaussSeidel.h
#ifndef GAUSSSEIDEL_H
#define GAUSSSEIDEL_H

#include "Variable.h"

class GaussSeidel {
public:
    static void compute_iteration(const Variable& u_k, Variable& u_kp1) {
        int n = u_k.size();
        const auto& u_k_values = u_k.getValues();
        auto& u_kp1_values = u_kp1.getValues();

        u_kp1_values[0] = u_k_values[0]; // 边界条件已经设置

        for (int i = 1; i < n - 1; ++i) {
            u_kp1_values[i] = 0.5 * (u_kp1_values[i - 1] + u_k_values[i + 1]);
        }

        u_kp1_values[n - 1] = u_k_values[n - 1]; // 边界条件已经设置
    }
};

#endif // GAUSSSEIDEL_H
