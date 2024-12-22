// Problem.h
#ifndef PROBLEM_H
#define PROBLEM_H

#include "Equation.h"
#include <memory>

class Problem {
private:
    Equation equation;
    std::unique_ptr<IMesh> mesh;

public:
    Problem(std::unique_ptr<IMesh> mesh);
    void solve();
    void solve_parallel(); 
    bool has_converged(const Variable& u_k, const Variable& u_kp1, double epsilon = 1e-5) const;
};

#endif // PROBLEM_H
