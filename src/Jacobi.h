// src/Jacobi.h
#ifndef JACOBI_H
#define JACOBI_H

#include "Variable.h"

class Jacobi {
public:
    static void compute_iteration(const Variable& u_k, Variable& u_kp1) {
        int n = u_k.size();
        for (int i = 1; i < n - 1; ++i) {
            u_kp1[i] = 0.5 * (u_k[i - 1] + u_k[i + 1]);
        }
    }
};

#endif // JACOBI_H
