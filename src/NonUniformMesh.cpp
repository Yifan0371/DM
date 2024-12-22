
#include "NonUniformMesh.h"
#include <cmath>

// Constructor for NonUniformMesh, initializing the non-uniform grid
NonUniformMesh::NonUniformMesh(double x_min, double x_max, double dx)
    : x_min(x_min), x_max(x_max), dx(dx) {
    // Calculate the number of points based on x_min, x_max, and dx
    int n_points = static_cast<int>(std::round((x_max - x_min) / dx)) + 1;
    x_points.resize(n_points);

    // Generate non-uniform points using a quadratic distribution
    for (int i = 0; i < n_points; ++i) {
        double ratio = static_cast<double>(i) / (n_points - 1); // Normalized position
        x_points[i] = x_min + (x_max - x_min) * std::pow(ratio, 2); // Quadratic scaling
    }
}

// Get the initial position of the mesh
double NonUniformMesh::getInitialPosition() const {
    return x_min;
}

// Get the final position of the mesh
double NonUniformMesh::getFinalPosition() const {
    return x_max;
}

// Get the total number of points in the mesh
int NonUniformMesh::getNumberOfPoints() const {
    return (int)x_points.size();
}

// Get the step size (dx) used for creating the mesh
double NonUniformMesh::getStepSize() const {
    return dx; 
}

// Get the total number of points in the mesh (same as getNumberOfPoints)
int NonUniformMesh::x_size() const {
    return (int)x_points.size();
}

// Get the x-coordinate of the ith point in the mesh
double NonUniformMesh::x_size(int i) const {
    return x_points[i];
}
