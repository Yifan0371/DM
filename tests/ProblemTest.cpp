#include "Problem.h"
#include "UniformMesh.h"
#include <gtest/gtest.h>
#include <memory>

TEST(UnitaryTest, ProblemTest) {
    // 测试正常情况下的 Problem
    {
        auto mesh = std::make_unique<UniformMesh>(0.0, 1.0, 0.1);
        Problem problem(std::move(mesh));
        EXPECT_NO_THROW(problem.solve());
    }

    // 测试提供空指针的情况，期望抛出异常
    {
        std::unique_ptr<IMesh> null_mesh = nullptr;
        Problem problem(std::move(null_mesh));
        EXPECT_THROW(problem.solve(), std::runtime_error);
    }
}
