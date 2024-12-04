#include "NonUniformMesh.h"
#include <stdexcept>

NonUniformMesh::NonUniformMesh(double x_min, double x_max, double dx)
    : x_min(x_min), x_max(x_max), dx(dx) {
    // 简单示例：生成非均匀分布的网格点
    if (x_max <= x_min || dx <= 0) {
        throw std::invalid_argument("Invalid mesh parameters.");
    }

    double x = x_min;
    while (x <= x_max) {
        positions.push_back(x);
        // 非均匀步长示例（这里简单地逐步增加 dx）
        x += dx;
        dx *= 1.1; // 步长逐渐增加
    }
}

double NonUniformMesh::getInitialPosition() const {
    return x_min;
}

double NonUniformMesh::getFinalPosition() const {
    return x_max;
}

int NonUniformMesh::getNumberOfPoints() const {
    return positions.size();
}

double NonUniformMesh::getStepSize() const {
    // 返回平均步长
    if (positions.size() < 2) {
        return 0.0;
    }
    return (positions.back() - positions.front()) / (positions.size() - 1);
}

int NonUniformMesh::x_size() const {
    return positions.size();
}

double NonUniformMesh::x_size(int i) const {
    if (i < 0 || i >= positions.size()) {
        throw std::out_of_range("Index out of range in NonUniformMesh::x_size");
    }
    return positions[i];
}
