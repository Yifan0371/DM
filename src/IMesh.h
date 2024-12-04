#ifndef IMESH_H
#define IMESH_H

class IMesh {
public:
    virtual ~IMesh() = default;  // 定义虚析构函数，确保派生类析构函数被正确调用

    virtual double getInitialPosition() const = 0;
    virtual double getFinalPosition() const = 0;
    virtual int getNumberOfPoints() const = 0;
    virtual double getStepSize() const = 0;
    virtual int x_size() const = 0;
    virtual double x_size(int i) const = 0;
};

#endif // IMESH_H
