#include "Problem.h"
#include "UniformMesh.h"
#include "NonUniformMesh.h"
#include <iostream>
#include <string>
#include <stdexcept>
#include <map>
#include <memory>

enum class MeshType {
    Uniform,
    NonUniform
};

// 工厂函数
std::unique_ptr<IMesh> createMesh(MeshType meshType, double x_min, double x_max, double dx) {
    switch (meshType) {
        case MeshType::Uniform:
            return std::make_unique<UniformMesh>(x_min, x_max, dx);
        case MeshType::NonUniform:
            return std::make_unique<NonUniformMesh>(x_min, x_max, dx);
        default:
            throw std::invalid_argument("Invalid mesh type.");
    }
}

// 字符串到枚举的映射
MeshType parseMeshType(const std::string& meshTypeStr) {
    static const std::map<std::string, MeshType> meshTypeMap = {
        {"uniform", MeshType::Uniform},
        {"non-uniform", MeshType::NonUniform}
    };

    auto it = meshTypeMap.find(meshTypeStr);
    if (it != meshTypeMap.end()) {
        return it->second;
    } else {
        throw std::invalid_argument("Unknown mesh type: " + meshTypeStr);
    }
}

int main(int argc, char** argv) {
    // 默认参数
    double x_min = 0.0;
    double x_max = 1.0;
    double dx = 0.01;
    std::string meshTypeStr = "uniform";

    // 解析命令行参数
    if (argc >= 4) {
        try {
            x_min = std::stod(argv[1]);
            x_max = std::stod(argv[2]);
            dx = std::stod(argv[3]);
        } catch (const std::exception& e) {
            std::cerr << "Invalid numerical arguments: " << e.what() << std::endl;
            return 1;
        }
    }

    if (argc >= 5) {
        meshTypeStr = argv[4];
    }

    // 创建网格实例
    try {
        MeshType meshType = parseMeshType(meshTypeStr);
        auto mesh = createMesh(meshType, x_min, x_max, dx);

        // 创建 Problem 实例
        Problem problem(std::move(mesh));

        // 求解问题
        problem.solve();
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
