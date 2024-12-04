// src/GaussSeidel.h
#ifndef GAUSSSEIDEL_H
#define GAUSSSEIDEL_H

#include "Variable.h"

class GaussSeidel {
public:
    static void compute_iteration(const Variable& u_k, Variable& u_kp1) {
        int n = u_k.size();
        u_kp1[0] = u_k[0]; // 边界条件已经设置
        for (int i = 1; i < n - 1; ++i) {
            u_kp1[i] = 0.5 * (u_kp1[i - 1] + u_k[i + 1]);
        }
        u_kp1[n - 1] = u_k[n - 1]; // 边界条件已经设置
    }
};

#endif // GAUSSSEIDEL_H
