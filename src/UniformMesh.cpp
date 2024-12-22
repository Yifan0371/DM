#include "UniformMesh.h"
#include <cmath>

// Constructor: Initializes a uniform mesh with given boundaries and step size
UniformMesh::UniformMesh(double x_min, double x_max, double dx)
    : x_min(x_min), x_max(x_max), dx(dx) {
    int n_points = static_cast<int>(std::round((x_max - x_min) / dx)) + 1;
    x_points.resize(n_points);
    for (int i = 0; i < n_points; ++i) {
        x_points[i] = x_min + i * dx; // Calculate each point in the mesh
    }
}

// Get the starting position of the mesh
double UniformMesh::getInitialPosition() const {
    return x_min;
}

// Get the ending position of the mesh
double UniformMesh::getFinalPosition() const {
    return x_max;
}

// Get the total number of points in the mesh
int UniformMesh::getNumberOfPoints() const {
    return (int)x_points.size();
}

// Get the step size of the mesh
double UniformMesh::getStepSize() const {
    return dx;
}

// Get the total number of points in the mesh (alternative method)
int UniformMesh::x_size() const {
    return (int)x_points.size();
}

// Get the coordinate value of a specific point in the mesh
double UniformMesh::x_size(int i) const {
    return x_points[i];
}
