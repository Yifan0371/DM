#include "UniformMesh.h"
#include "NonUniformMesh.h"
#include <gtest/gtest.h>

TEST(UnitaryTest, MeshTest) {
    // 测试 UniformMesh
    double x_min = 0.0;
    double x_max = 1.0;
    double dx = 0.1;

    UniformMesh uniformMesh(x_min, x_max, dx);

    EXPECT_DOUBLE_EQ(uniformMesh.getInitialPosition(), x_min);
    EXPECT_DOUBLE_EQ(uniformMesh.getFinalPosition(), x_max);
    EXPECT_EQ(uniformMesh.getNumberOfPoints(), 11);
    EXPECT_DOUBLE_EQ(uniformMesh.getStepSize(), 0.1);
    EXPECT_EQ(uniformMesh.x_size(), 11);
    EXPECT_DOUBLE_EQ(uniformMesh.x_size(0), x_min);
    EXPECT_DOUBLE_EQ(uniformMesh.x_size(10), x_max);

    // 测试 NonUniformMesh
    NonUniformMesh nonUniformMesh(x_min, x_max, dx);

    EXPECT_DOUBLE_EQ(nonUniformMesh.getInitialPosition(), x_min);
    EXPECT_DOUBLE_EQ(nonUniformMesh.getFinalPosition(), x_max);
    EXPECT_EQ(nonUniformMesh.getNumberOfPoints(), 11);
    EXPECT_DOUBLE_EQ(nonUniformMesh.getStepSize(), dx);
    EXPECT_EQ(nonUniformMesh.x_size(), 11);
    EXPECT_DOUBLE_EQ(nonUniformMesh.x_size(0), x_min);
    EXPECT_DOUBLE_EQ(nonUniformMesh.x_size(10), x_max);
}
