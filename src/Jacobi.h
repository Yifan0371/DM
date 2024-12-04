// Jacobi.h
#ifndef JACOBI_H
#define JACOBI_H

#include "Variable.h"

class Jacobi {
public:
    static void compute_iteration(const Variable& u_k, Variable& u_kp1) {
        int n = u_k.size();
        const auto& u_k_values = u_k.getValues();
        auto& u_kp1_values = u_kp1.getValues();

        for (int i = 1; i < n - 1; ++i) {
            u_kp1_values[i] = 0.5 * (u_k_values[i - 1] + u_k_values[i + 1]);
        }
    }
};

#endif // JACOBI_H
