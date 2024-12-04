// Variable.cpp
#include "Variable.h"
#include <iostream>
#include <fstream>

Variable::Variable(IMesh* mesh) : mesh(mesh) {
    if (!mesh) {
        throw std::invalid_argument("Mesh pointer is null in Variable constructor");
    }
    int size = mesh->x_size();
    if (size <= 0) {
        throw std::invalid_argument("Invalid mesh size.");
    }
    values.resize(size, 0.0);
}

double& Variable::operator[](int i) {
    if (i < 0 || i >= values.size()) {
        throw std::out_of_range("Index out of range in Variable::operator[]");
    }
    return values[i];
}

const double& Variable::operator[](int i) const {
    if (i < 0 || i >= values.size()) {
        throw std::out_of_range("Index out of range in Variable::operator[]");
    }
    return values[i];
}

int Variable::size() const {
    return values.size();
}

IMesh* Variable::getMesh() const {
    return mesh;
}

Variable& Variable::operator=(const Variable& other) {
    if (this != &other) {
        mesh = other.mesh;
        values = other.values;
        m_name = other.m_name;
    }
    return *this;
}

void Variable::setName(const std::string& name) {
    m_name = name;
}

const std::string& Variable::getName() const {
    return m_name;
}

void Variable::print() const {
    // 显示变量名称
    std::cout << "Variable: " << m_name << std::endl;

    // 显示变量值
    for (int i = 0; i < values.size(); ++i) {
        std::cout << "x[" << i << "] = " << mesh->x_size(i)
                  << ", " << m_name << "[" << i << "] = " << values[i] << std::endl;
    }

    // 导出到文件
    std::string filename = "Variable_" + m_name + ".data";
    std::ofstream outfile(filename);
    if (outfile.is_open()) {
        for (int i = 0; i < values.size(); ++i) {
            outfile << mesh->x_size(i) << " " << values[i] << std::endl;
        }
        outfile.close();
        std::cout << "Data exported to " << filename << std::endl;
    } else {
        std::cerr << "Failed to open file " << filename << " for writing." << std::endl;
    }
}
