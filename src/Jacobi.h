#ifndef JACOBI_H
#define JACOBI_H

#include "Variable.h"
#include <vector>
#include <algorithm>
#include <numeric>
#include <execution> // Include for parallel execution policies

// Class implementing the Jacobi iterative solver
class Jacobi {
public:
    // Static method to compute one iteration of the Jacobi method
    static void compute_iteration(const Variable& u_k, Variable& u_kp1) {
        int n = u_k.size(); // Number of points in the variable
        const auto& u_k_values = u_k.getValues(); // Values from the current iteration
        auto& u_kp1_values = u_kp1.getValues();   // Values for the next iteration

        // Generate indices for interior points
        std::vector<int> indices(n - 2);
        std::iota(indices.begin(), indices.end(), 1);

        // Perform Jacobi updates in parallel
        std::transform(std::execution::par, indices.begin(), indices.end(), u_kp1_values.begin() + 1,
                       [&u_k_values](int i) {
                           return 0.5 * (u_k_values[i - 1] + u_k_values[i + 1]); // Update rule
                       });
    }
};

#endif // JACOBI_H
