#include "Problem.h"
#include "UniformMesh.h"
#include <gtest/gtest.h>
#include <memory>

TEST(UnitaryTest, ProblemTest) {
    // Test Problem with a valid mesh
    {
        // Create a uniform mesh
        auto mesh = std::make_unique<UniformMesh>(0.0, 1.0, 0.1);
        Problem problem(std::move(mesh));

        // Ensure the solve function does not throw exceptions
        EXPECT_NO_THROW(problem.solve());
    }

    // Test Problem with a null mesh pointer
    {
        // Pass a null mesh pointer
        std::unique_ptr<IMesh> null_mesh = nullptr;
        Problem problem(std::move(null_mesh));

        // Ensure the solve function throws a runtime error
        EXPECT_THROW(problem.solve(), std::runtime_error);
    }
}
