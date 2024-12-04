#include "Equation.h"
#include "Variable.h"
#include "UniformMesh.h"
#include "Jacobi.h"
#include <gtest/gtest.h>

TEST(MainFunctionTest, EquationTest) {
    // 创建一个网格
    UniformMesh mesh(0.0, 1.0, 0.1);
    Variable u_k(&mesh);
    Variable u_kp1(&mesh);
    Equation equation;

    // 定义初始条件函数
    auto init_func = [](double x) { return x; };
    EXPECT_NO_THROW(equation.compute_initial_condition(u_k, init_func));

    // 测试边界条件
    EXPECT_NO_THROW(equation.compute_boundary_conditions(u_kp1));

    // 测试 compute_for_solver
    EXPECT_NO_THROW(equation.compute_for_solver<Jacobi>(u_k, u_kp1));

    // 测试 compute_residual
    Variable residual(&mesh);
    EXPECT_NO_THROW(equation.compute_residual(u_kp1, residual));
}
