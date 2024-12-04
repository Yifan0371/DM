// Variable.h
#ifndef VARIABLE_H
#define VARIABLE_H

#include "IMesh.h"
#include <vector>
#include <string>

class Variable {
private:
    IMesh* mesh;
    std::vector<double> values;
    std::string m_name; // 新增的成员变量

public:
    Variable(IMesh* mesh);

    double& operator[](int i);
    const double& operator[](int i) const;

    int size() const;
    IMesh* getMesh() const;

    Variable& operator=(const Variable& other);

    // 新增的方法
    void setName(const std::string& name);
    const std::string& getName() const;

    void print() const;
};

#endif // VARIABLE_H
