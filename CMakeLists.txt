cmake_minimum_required(VERSION 3.10)

# 设置项目名称
project(LaplaceSimulator)

# 设置C++标准
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# 启用测试
enable_testing()

# 包含头文件目录
include_directories(src)

# 主程序源文件
set(SOURCES
    src/main.cpp
    src/Problem.cpp
    src/Equation.cpp
    src/UniformMesh.cpp
    src/NonUniformMesh.cpp  # 添加新的源文件
    src/Variable.cpp
)

# 添加主程序可执行文件
add_executable(LaplaceSimulator ${SOURCES})

# 添加一个运行主程序的测试
add_test(NAME structure_test COMMAND LaplaceSimulator)

# 查找 GTest 库
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# 测试源文件
set(TEST_SOURCES
    src/test.cpp
    src/Equation.cpp
    src/Problem.cpp
    src/UniformMesh.cpp
    src/NonUniformMesh.cpp  # 添加新的源文件
    src/Variable.cpp
)

# 添加测试可执行文件
add_executable(UnitTests ${TEST_SOURCES})

# 链接 GTest 库和 pthread 库
target_link_libraries(UnitTests GTest::GTest GTest::Main pthread)

# 使用 gtest_discover_tests 自动发现测试
include(GoogleTest)
gtest_discover_tests(UnitTests)
