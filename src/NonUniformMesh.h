// src/NonUniformMesh.h
#ifndef NONUNIFORMMESH_H
#define NONUNIFORMMESH_H

#include "IMesh.h"
#include <vector>

class NonUniformMesh : public IMesh {
private:
    double x_min;
    double x_max;
    double dx;
    std::vector<double> x_points;

public:
    NonUniformMesh(double x_min, double x_max, double dx);

    double getInitialPosition() const override;
    double getFinalPosition() const override;
    int getNumberOfPoints() const override;
    double getStepSize() const override;

    int x_size() const override;
    double x_size(int i) const override;
};

#endif // NONUNIFORMMESH_H
