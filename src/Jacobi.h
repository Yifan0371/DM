#ifndef JACOBI_H
#define JACOBI_H

#include "Variable.h"
#include <vector>
#include <algorithm>
#include <numeric>
#include <execution> // 使用并行执行策略

class Jacobi {
public:
    static void compute_iteration(const Variable& u_k, Variable& u_kp1) {
        int n = u_k.size();
        const auto& u_k_values = u_k.getValues();
        auto& u_kp1_values = u_kp1.getValues();

        std::vector<int> indices(n - 2);
        std::iota(indices.begin(), indices.end(), 1);

        // 使用并行执行策略加速 Jacobi 更新
        std::transform(std::execution::par, indices.begin(), indices.end(), u_kp1_values.begin() + 1,
                       [&u_k_values](int i) {
                           return 0.5 * (u_k_values[i - 1] + u_k_values[i + 1]);
                       });
    }
};

#endif // JACOBI_H
