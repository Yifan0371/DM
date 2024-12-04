#ifndef EQUATION_H
#define EQUATION_H

#include "IMesh.h"
#include "Variable.h"


class Equation {
public:
    void compute_initial_condition(Variable& u, IMesh* mesh);//初始化
    void compute_boundary_conditions(Variable& u, IMesh* mesh);//边界赋值
    void compute(Variable& u_k, Variable& u_kp1,IMesh* mesh);//计算主函数
    



};

#endif // EQUATION_H
