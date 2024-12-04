#include "NonUniformMesh.h"
#include <cmath>

NonUniformMesh::NonUniformMesh(double x_min, double x_max, double dx)
    : x_min(x_min), x_max(x_max), dx(dx) {
    int n_points = static_cast<int>(std::round((x_max - x_min) / dx)) + 1;
    x_points.resize(n_points);
    for (int i = 0; i < n_points; ++i) {
        double ratio = static_cast<double>(i) / (n_points - 1);
        x_points[i] = x_min + (x_max - x_min) * std::pow(ratio, 2); // 示例的非均匀分布
    }
}

double NonUniformMesh::getInitialPosition() const {
    return x_min;
}

double NonUniformMesh::getFinalPosition() const {
    return x_max;
}

int NonUniformMesh::getNumberOfPoints() const {
    return x_points.size();
}

double NonUniformMesh::getStepSize() const {
    return dx; // 对于非均匀网格，这个值可能没有实际意义
}

int NonUniformMesh::x_size() const {
    return x_points.size();
}

double NonUniformMesh::x_size(int i) const {
    return x_points[i];
}
