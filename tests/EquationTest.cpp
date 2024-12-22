#include "Equation.h"
#include "Variable.h"
#include "UniformMesh.h"
#include "Jacobi.h"
#include <gtest/gtest.h>

TEST(MainFunctionTest, EquationTest) {
    
    UniformMesh mesh(0.0, 1.0, 0.1);
    Variable u_k(&mesh);
    Variable u_kp1(&mesh);
    Equation equation;

    auto init_func = [](double x) { return x; };
    EXPECT_NO_THROW(equation.compute_initial_condition(u_k, init_func));


    EXPECT_NO_THROW(equation.compute_boundary_conditions(u_kp1));

 
    EXPECT_NO_THROW(equation.compute_for_solver<Jacobi>(u_k, u_kp1));

  
    Variable residual(&mesh);
    EXPECT_NO_THROW(equation.compute_residual(u_kp1, residual));
}
