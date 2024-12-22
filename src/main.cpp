#include "Problem.h"
#include "UniformMesh.h"
#include "NonUniformMesh.h"
#include <iostream>
#include <string>
#include <stdexcept>
#include <map>
#include <memory>

// Enum to define the types of mesh available
enum class MeshType {
    Uniform,     // Represents a uniform mesh
    NonUniform   // Represents a non-uniform mesh
};

// Factory function to create a mesh based on the specified type
std::unique_ptr<IMesh> createMesh(MeshType meshType, double x_min, double x_max, double dx) {
    switch (meshType) {
        case MeshType::Uniform:
            return std::make_unique<UniformMesh>(x_min, x_max, dx);
        case MeshType::NonUniform:
            return std::make_unique<NonUniformMesh>(x_min, x_max, dx);
        default:
            // Throw an exception if the mesh type is invalid
            throw std::invalid_argument("Invalid mesh type.");
    }
}

// Function to parse a string into a MeshType
MeshType parseMeshType(const std::string& meshTypeStr) {
    // Map of string representations to MeshType enums
    static const std::map<std::string, MeshType> meshTypeMap = {
        {"uniform", MeshType::Uniform},
        {"non-uniform", MeshType::NonUniform}
    };

    // Find the corresponding MeshType or throw an exception if not found
    auto it = meshTypeMap.find(meshTypeStr);
    if (it != meshTypeMap.end()) {
        return it->second;
    } else {
        throw std::invalid_argument("Unknown mesh type: " + meshTypeStr);
    }
}

// Main function of the program
int main(int argc, char** argv) {
    // Default parameters for the mesh
    double x_min = 0.0;
    double x_max = 1.0;
    double dx = 0.01;
    std::string meshTypeStr = "uniform"; // Default mesh type

    // Parse command-line arguments for mesh parameters
    if (argc >= 4) {
        try {
            x_min = std::stod(argv[1]);  // Parse the starting position of the mesh
            x_max = std::stod(argv[2]);  // Parse the ending position of the mesh
            dx = std::stod(argv[3]);     // Parse the step size
        } catch (const std::exception& e) {
            std::cerr << "Invalid numerical arguments: " << e.what() << std::endl;
            return 1; // Exit with error code if arguments are invalid
        }
    }

    // Parse command-line argument for the mesh type
    if (argc >= 5) {
        meshTypeStr = argv[4];
    }

    try {
        // Parse the mesh type from the input string
        MeshType meshType = parseMeshType(meshTypeStr);
        
        // Create the mesh using the specified parameters
        auto mesh = createMesh(meshType, x_min, x_max, dx);

        // Create a Problem instance with the generated mesh
        Problem problem(std::move(mesh));

        // Solve the problem sequentially
        problem.solve();

        // Solve the problem in parallel
        problem.solve_parallel();

    } catch (const std::exception& e) {
        // Catch and print any exceptions that occur during execution
        std::cerr << "Error: " << e.what() << std::endl;
        return 1; // Exit with error code if an exception occurs
    }

    return 0; // Exit successfully
}
