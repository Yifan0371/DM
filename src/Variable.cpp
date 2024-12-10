// Variable.cpp
#include "Variable.h"
#include <stdexcept>
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
    if (i < 0 || i >= (int)values.size()) {
        throw std::out_of_range("Index out of range in Variable::operator[]");
    }
    return values[i];
}

const double& Variable::operator[](int i) const {
    if (i < 0 || i >= (int)values.size()) {
        throw std::out_of_range("Index out of range in Variable::operator[]");
    }
    return values[i];
}

int Variable::size() const {
    return (int)values.size();
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
    std::cout << "Variable: " << m_name << std::endl;

    std::string filename = m_name + ".data";
    std::ofstream outfile(filename);
    if (outfile.is_open()) {
        for (int i = 0; i < (int)values.size(); ++i) {
            outfile << mesh->x_size(i) << " " << values[i] << "\n";
        }
        outfile.close();
        std::cout << "Data exported to " << filename << std::endl;
    } else {
        std::cerr << "Failed to open file " << filename << " for writing." << std::endl;
    }
}

void Variable::exportToVTK(const std::string& filename) const {
    std::ofstream outfile(filename);
    if (!outfile.is_open()) {
        std::cerr << "Failed to open file " << filename << " for writing." << std::endl;
        return;
    }

    int num_points = size();
    outfile << "# vtk DataFile Version 3.0\n";
    outfile << "VTK file containing grid data\n";
    outfile << "ASCII\n";
    outfile << "DATASET STRUCTURED_GRID\n";
    outfile << "DIMENSIONS " << num_points << " 1 1\n";
    outfile << "POINTS " << num_points << " double\n";

    for (int i = 0; i < num_points; ++i) {
        outfile << mesh->x_size(i) << " 0 0\n";
    }

    outfile << "POINT_DATA " << num_points << "\n";
    outfile << "SCALARS " << m_name << " double\n";
    outfile << "LOOKUP_TABLE default\n";

    for (double val : values) {
        outfile << val << "\n";
    }

    outfile.close();
    std::cout << "VTK data exported to " << filename << std::endl;
}

const std::vector<double>& Variable::getValues() const {
    return values;
}

std::vector<double>& Variable::getValues() {
    return values;
}
