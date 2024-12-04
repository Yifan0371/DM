#include "Equation.h"
#include <iostream>

void Equation::compute_initial_condition(Variable &u, IMesh *mesh)
{
    double T1=30;
    double T2=15;

    int mid_point=mesh->x_size()/2;

    for (int i = 0;i<mid_point;++i){
        u[i]=T1;
    }
    
    for (int i = mid_point;i<mesh->x_size();++i){
        u[i]=T2;
    }

}


void Equation::compute_boundary_conditions(Variable& u, IMesh* mesh) {
    double T1 = 30.0;
    double T2 = 15.0;

    // 设置边界条件
    u[0] = T1;               // 左边界
    u[mesh->x_size() - 1] = T2; // 右边界
}

void Equation::compute(Variable& u_k, Variable& u_kp1, IMesh* mesh) {
    int n = u_k.size();

    for (int i = 1; i < n - 1; ++i) {
        double x_i = mesh->x_size(i);
        double x_i_minus = mesh->x_size(i - 1);
        double x_i_plus = mesh->x_size(i + 1);

        double dx_minus = x_i - x_i_minus;
        double dx_plus = x_i_plus - x_i;

        // 使用加权平均，考虑非均匀网格
        u_kp1[i] = ((u_k[i - 1] / dx_minus) + (u_k[i + 1] / dx_plus)) / ((1.0 / dx_minus) + (1.0 / dx_plus));
    }
}
