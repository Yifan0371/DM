#ifndef GAUSSSEIDEL_H
#define GAUSSSEIDEL_H

#include "Variable.h"
#include <vector>
#include <algorithm>
#include <numeric>

class GaussSeidel {
public:
    // Perform a single iteration of the Gauss-Seidel method.
    // Updates the variable u_kp1 using the values from u_k and the previously updated values in u_kp1.
    static void compute_iteration(const Variable& u_k, Variable& u_kp1) {
        // Get the size of the variable.
        int n = u_k.size();
        const auto& u_k_values = u_k.getValues(); // Access the current iteration values.
        auto& u_kp1_values = u_kp1.getValues();  // Access the next iteration values.

        // Set the boundary values (Dirichlet boundary conditions).
        u_kp1_values[0] = u_k_values[0];       // Left boundary remains unchanged.
        u_kp1_values[n - 1] = u_k_values[n - 1]; // Right boundary remains unchanged.

        // Create indices for the interior points (excluding boundaries).
        std::vector<int> indices(n - 2);
        std::iota(indices.begin(), indices.end(), 1); // Fill with values from 1 to n-2.

        // Update the interior points using the Gauss-Seidel formula.
        std::for_each(indices.begin(), indices.end(),
                      [&u_k_values, &u_kp1_values](int i) {
                          u_kp1_values[i] = 0.5 * (u_kp1_values[i - 1] + u_k_values[i + 1]);
                          // New value depends on the previous updated value (u_kp1[i-1])
                          // and the current iteration value (u_k[i+1]).
                      });
    }
};

#endif // GAUSSSEIDEL_H
