#ifndef NONUNIFORMMESH_H
#define NONUNIFORMMESH_H

#include "IMesh.h"
#include <vector>

// Class representing a non-uniform mesh
class NonUniformMesh : public IMesh {
private:
    double x_min;                     // Minimum x-coordinate of the mesh
    double x_max;                     // Maximum x-coordinate of the mesh
    double dx;                        // Approximate step size for generating points
    std::vector<double> x_points;    // Vector to store the non-uniform points

public:
    // Constructor to initialize the non-uniform mesh with given bounds and step size
    NonUniformMesh(double x_min, double x_max, double dx);

    // Override methods from the IMesh interface
    double getInitialPosition() const override;  // Get the initial position of the mesh
    double getFinalPosition() const override;    // Get the final position of the mesh
    int getNumberOfPoints() const override;      // Get the total number of points in the mesh
    double getStepSize() const override;         // Get the step size used to generate the mesh

    int x_size() const override;                 // Get the total number of points in the mesh
    double x_size(int i) const override;         // Get the x-coordinate of the ith point
};

#endif // NONUNIFORMMESH_H
