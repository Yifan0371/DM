#ifndef PROBLEM_H
#define PROBLEM_H

#include "Equation.h"
#include "IMesh.h"
#include "Variable.h"
#include <memory>

class Problem {
private:
    Equation equation;
    std::unique_ptr<IMesh> mesh;
    int iterationCount;
public:
    Problem(std::unique_ptr<IMesh> mesh);
    ~Problem();
    void solve();
    bool has_converged(Variable& u_k, Variable& u_kp1, double epsilon = 1e-5) const;
};

#endif // PROBLEM_H
