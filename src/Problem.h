// src/Problem.h
#ifndef PROBLEM_H
#define PROBLEM_H

#include "Equation.h"
#include "IMesh.h"
#include <memory>
#include <functional>

class Problem {
private:
    Equation equation;
    std::unique_ptr<IMesh> mesh;

public:
    Problem(std::unique_ptr<IMesh> mesh);
    ~Problem();
    void solve();
    bool has_converged(const Variable& u_k, const Variable& u_kp1, double epsilon = 1e-5) const;
};

#endif // PROBLEM_H
