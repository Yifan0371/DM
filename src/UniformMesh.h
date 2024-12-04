// UniformMesh.h
#ifndef UNIFORMMESH_H
#define UNIFORMMESH_H

#include "IMesh.h"

class UniformMesh : public IMesh {
private:
    double x_min;
    double x_max;
    double dx;

public:
    UniformMesh(double x_min, double x_max, double dx);
    double getInitialPosition() const override;
    double getFinalPosition() const override;
    int getNumberOfPoints() const override;
    double getStepSize() const override;
    int x_size() const override;
    double x_size(int i) const override;
};

#endif // UNIFORMMESH_H
