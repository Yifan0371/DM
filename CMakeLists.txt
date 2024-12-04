# CMakeLists.txt
cmake_minimum_required(VERSION 3.14)
project(LaplaceSimulator)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# 主可执行文件
add_executable(LaplaceSimulator
    src/main.cpp
    src/Problem.cpp
    src/Equation.cpp
    src/Variable.cpp
    src/UniformMesh.cpp
    src/NonUniformMesh.cpp
)

# 包含头文件目录
target_include_directories(LaplaceSimulator PRIVATE src)

# 启用测试
enable_testing()

# 添加 GTest
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/release-1.12.1.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# 添加测试可执行文件
add_executable(LaplaceSimulatorTests
    tests/UniformMeshTest.cpp
    tests/ProblemTest.cpp
    tests/EquationTest.cpp
    src/Problem.cpp
    src/Equation.cpp
    src/Variable.cpp
    src/UniformMesh.cpp
    src/NonUniformMesh.cpp
)

# 链接 GTest 库
target_link_libraries(LaplaceSimulatorTests GTest::gtest_main)

# 包含头文件目录
target_include_directories(LaplaceSimulatorTests PUBLIC src)

# 添加测试
include(GoogleTest)
gtest_discover_tests(LaplaceSimulatorTests)
