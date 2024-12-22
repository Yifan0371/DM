#ifndef IMESH_H
#define IMESH_H

// Abstract interface for mesh representation
class IMesh {
public:
    // Virtual destructor for polymorphic base class
    virtual ~IMesh() = default;

    // Returns the initial position of the mesh
    virtual double getInitialPosition() const = 0;

    // Returns the final position of the mesh
    virtual double getFinalPosition() const = 0;

    // Returns the total number of points in the mesh
    virtual int getNumberOfPoints() const = 0;

    // Returns the step size (distance between points) in the mesh
    virtual double getStepSize() const = 0;

    // Returns the total number of points along the x-dimension
    virtual int x_size() const = 0;

    // Returns the x-coordinate of the ith point in the mesh
    virtual double x_size(int i) const = 0;
};

#endif // IMESH_H
