# Laplace Equation Solver

A numerical solver for the Laplace equation that implements both Jacobi and Gauss-Seidel iteration methods, supporting uniform and non-uniform grids.

## Requirements

- C++17 compiler (GCC 7+ or Clang 5+)
- CMake 3.10+
- ParaView (optional, for visualization)
## Building the Project

```bash
mkdir build && cd build
cmake ..
make
```

## Running the Solver

Basic usage:
```bash
./LaplaceSimulator <x_min> <x_max> <dx> <mesh_type>
```

Example:
```bash
./LaplaceSimulator 0.0 1.0 0.01 uniform
```

## Output Files

All computation results and analysis files will be stored in the `results` directory. This includes:

- Numerical solutions in `.data` format
- Visualization files in `.vtk` format
- Performance metrics and timing data
- Convergence analysis results
- Unit test reports

## Visualization

The solver generates ParaView-compatible `.vtk` files that can be loaded directly for visualization. To view the results:

1. Open ParaView
2. Load the `.vtk` files from the results directory
3. Select visualization preferences (e.g., Surface with Edges)

## Testing

Run the test suite:
```bash
./LaplaceSimulatorTests
```

All output files are now organized in the results directory for better data management and analysis.

For visualization of numerical results, the generated `.vtk` files in the results directory can be directly loaded into ParaView. 