#include "UniformMesh.h"
#include "NonUniformMesh.h"
#include <gtest/gtest.h>

TEST(UnitaryTest, MeshTest) {
    // Test UniformMesh
    double x_min = 0.0; // Start position
    double x_max = 1.0; // End position
    double dx = 0.1;    // Step size

    // Create a UniformMesh instance
    UniformMesh uniformMesh(x_min, x_max, dx);

    // Validate initial position
    EXPECT_DOUBLE_EQ(uniformMesh.getInitialPosition(), x_min);
    // Validate final position
    EXPECT_DOUBLE_EQ(uniformMesh.getFinalPosition(), x_max);
    // Validate the number of points
    EXPECT_EQ(uniformMesh.getNumberOfPoints(), 11);
    // Validate the step size
    EXPECT_DOUBLE_EQ(uniformMesh.getStepSize(), 0.1);
    // Validate the size of the mesh
    EXPECT_EQ(uniformMesh.x_size(), 11);
    // Validate the position of the first point
    EXPECT_DOUBLE_EQ(uniformMesh.x_size(0), x_min);
    // Validate the position of the last point
    EXPECT_DOUBLE_EQ(uniformMesh.x_size(10), x_max);

    // Test NonUniformMesh
    NonUniformMesh nonUniformMesh(x_min, x_max, dx);

    // Validate initial position
    EXPECT_DOUBLE_EQ(nonUniformMesh.getInitialPosition(), x_min);
    // Validate final position
    EXPECT_DOUBLE_EQ(nonUniformMesh.getFinalPosition(), x_max);
    // Validate the number of points
    EXPECT_EQ(nonUniformMesh.getNumberOfPoints(), 11);
    // Validate the step size
    EXPECT_DOUBLE_EQ(nonUniformMesh.getStepSize(), dx);
    // Validate the size of the mesh
    EXPECT_EQ(nonUniformMesh.x_size(), 11);
    // Validate the position of the first point
    EXPECT_DOUBLE_EQ(nonUniformMesh.x_size(0), x_min);
    // Validate the position of the last point
    EXPECT_DOUBLE_EQ(nonUniformMesh.x_size(10), x_max);
}
