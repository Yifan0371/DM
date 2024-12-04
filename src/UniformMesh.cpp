#include "UniformMesh.h"
#include <cmath>

UniformMesh::UniformMesh(double x_min, double x_max, double dx)
    : x_min(x_min), x_max(x_max), dx(dx) {
    int n_points = static_cast<int>(std::round((x_max - x_min) / dx)) + 1;
    x_points.resize(n_points);
    for (int i = 0; i < n_points; ++i) {
        x_points[i] = x_min + i * dx;
    }
}

double UniformMesh::getInitialPosition() const {
    return x_min;
}

double UniformMesh::getFinalPosition() const {
    return x_max;
}

int UniformMesh::getNumberOfPoints() const {
    return x_points.size();
}

double UniformMesh::getStepSize() const {
    return dx;
}

int UniformMesh::x_size() const {
    return x_points.size();
}

double UniformMesh::x_size(int i) const {
    return x_points[i];
}
