// UniformMesh.cpp
#include "UniformMesh.h"

UniformMesh::UniformMesh(double x_min, double x_max, double dx)
    : x_min(x_min), x_max(x_max), dx(dx) {}

double UniformMesh::getInitialPosition() const {
    return x_min;
}

double UniformMesh::getFinalPosition() const {
    return x_max;
}

int UniformMesh::getNumberOfPoints() const {
    return static_cast<int>((x_max - x_min) / dx) + 1;
}

double UniformMesh::getStepSize() const {
    return dx;
}

int UniformMesh::x_size() const
{
    return getNumberOfPoints();
}

double UniformMesh::x_size(int i) const
{
    return getInitialPosition() + i * getStepSize();    
}
