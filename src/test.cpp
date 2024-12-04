// test.cpp
#include <gtest/gtest.h>
#include "UniformMesh.h"
#include "Variable.h"
#include "Problem.h"
#include "Equation.h"

// 测试UniformMesh类
TEST(UnitTest, UniformMeshTest) {
    UniformMesh mesh(0.0, 1.0, 0.2);

    EXPECT_DOUBLE_EQ(mesh.getInitialPosition(), 0.0);
    EXPECT_DOUBLE_EQ(mesh.getFinalPosition(), 1.0);
    EXPECT_DOUBLE_EQ(mesh.getStepSize(), 0.2);
    EXPECT_EQ(mesh.getNumberOfPoints(), 6);
    EXPECT_EQ(mesh.x_size(), 6);
    EXPECT_DOUBLE_EQ(mesh.x_size(0), 0.0);
    EXPECT_DOUBLE_EQ(mesh.x_size(5), 1.0);
}

// 测试Variable类
TEST(UnitTest, VariableTest) {
    UniformMesh mesh(0.0, 1.0, 0.2);
    Variable var(&mesh);

    EXPECT_EQ(var.size(), 6);

    // 测试operator[]
    var[0] = 10.0;
    EXPECT_DOUBLE_EQ(var[0], 10.0);
}

// 测试Equation类
TEST(UnitTest, EquationTest) {
    UniformMesh mesh(0.0, 1.0, 0.2);
    Variable u_k(&mesh);
    Variable u_kp1(&mesh);
    Equation equation;

    // 初始化条件
    equation.compute_initial_condition(u_k, &mesh);

    // 边界条件
    equation.compute_boundary_conditions(u_kp1, &mesh);

    // 计算
    EXPECT_NO_THROW(equation.compute(u_k, u_kp1,&mesh));
}

TEST(UnitTest, ProblemTest) {
    // 创建 std::unique_ptr<IMesh>，并使用 std::make_unique
    auto mesh = std::make_unique<UniformMesh>(0.0, 1.0, 0.2);

    // 将所有权转移给 Problem 对象
    Problem problem(std::move(mesh));

    // 测试 solve 方法
    EXPECT_NO_THROW(problem.solve());

    // 不需要手动 delete，unique_ptr 会自动管理内存
}
