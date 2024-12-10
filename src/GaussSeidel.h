#ifndef GAUSSSEIDEL_H
#define GAUSSSEIDEL_H

#include "Variable.h"
#include <vector>
#include <algorithm>
#include <numeric>

class GaussSeidel {
public:
    static void compute_iteration(const Variable& u_k, Variable& u_kp1) {
        int n = u_k.size();
        const auto& u_k_values = u_k.getValues();
        auto& u_kp1_values = u_kp1.getValues();

        u_kp1_values[0] = u_k_values[0];
        u_kp1_values[n - 1] = u_k_values[n - 1];

        std::vector<int> indices(n - 2);
        std::iota(indices.begin(), indices.end(), 1);

        // Gauss-Seidel需要前面已更新的点，因此使用for_each
        std::for_each(indices.begin(), indices.end(),
                      [&u_k_values, &u_kp1_values](int i) {
                          u_kp1_values[i] = 0.5 * (u_kp1_values[i - 1] + u_k_values[i + 1]);
                      });
    }
};

#endif // GAUSSSEIDEL_H
