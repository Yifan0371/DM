// Variable.h
#ifndef VARIABLE_H
#define VARIABLE_H

#include <vector>
#include <string>
#include "IMesh.h"

class Variable {
private:
    IMesh* mesh;
    std::vector<double> values;
    std::string m_name;

public:
    Variable(IMesh* mesh);

    double& operator[](int i);
    const double& operator[](int i) const;

    int size() const;
    IMesh* getMesh() const;

    Variable& operator=(const Variable& other);

    void setName(const std::string& name);
    const std::string& getName() const;

    void print() const;
    void exportToVTK(const std::string& filename) const;

    const std::vector<double>& getValues() const;
    std::vector<double>& getValues();
};

#endif // VARIABLE_H
