# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.31

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /opt/homebrew/bin/cmake

# The command to remove a file.
RM = /opt/homebrew/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/yifanli/Desktop/M1/c++项目/DM

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/yifanli/Desktop/M1/c++项目/DM/build

# Include any dependencies generated for this target.
include CMakeFiles/LaplaceSimulator.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/LaplaceSimulator.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/LaplaceSimulator.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/LaplaceSimulator.dir/flags.make

CMakeFiles/LaplaceSimulator.dir/codegen:
.PHONY : CMakeFiles/LaplaceSimulator.dir/codegen

CMakeFiles/LaplaceSimulator.dir/src/main.cpp.o: CMakeFiles/LaplaceSimulator.dir/flags.make
CMakeFiles/LaplaceSimulator.dir/src/main.cpp.o: /Users/yifanli/Desktop/M1/c++项目/DM/src/main.cpp
CMakeFiles/LaplaceSimulator.dir/src/main.cpp.o: CMakeFiles/LaplaceSimulator.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/yifanli/Desktop/M1/c++项目/DM/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/LaplaceSimulator.dir/src/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/LaplaceSimulator.dir/src/main.cpp.o -MF CMakeFiles/LaplaceSimulator.dir/src/main.cpp.o.d -o CMakeFiles/LaplaceSimulator.dir/src/main.cpp.o -c /Users/yifanli/Desktop/M1/c++项目/DM/src/main.cpp

CMakeFiles/LaplaceSimulator.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/LaplaceSimulator.dir/src/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/yifanli/Desktop/M1/c++项目/DM/src/main.cpp > CMakeFiles/LaplaceSimulator.dir/src/main.cpp.i

CMakeFiles/LaplaceSimulator.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/LaplaceSimulator.dir/src/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/yifanli/Desktop/M1/c++项目/DM/src/main.cpp -o CMakeFiles/LaplaceSimulator.dir/src/main.cpp.s

CMakeFiles/LaplaceSimulator.dir/src/Problem.cpp.o: CMakeFiles/LaplaceSimulator.dir/flags.make
CMakeFiles/LaplaceSimulator.dir/src/Problem.cpp.o: /Users/yifanli/Desktop/M1/c++项目/DM/src/Problem.cpp
CMakeFiles/LaplaceSimulator.dir/src/Problem.cpp.o: CMakeFiles/LaplaceSimulator.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/yifanli/Desktop/M1/c++项目/DM/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/LaplaceSimulator.dir/src/Problem.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/LaplaceSimulator.dir/src/Problem.cpp.o -MF CMakeFiles/LaplaceSimulator.dir/src/Problem.cpp.o.d -o CMakeFiles/LaplaceSimulator.dir/src/Problem.cpp.o -c /Users/yifanli/Desktop/M1/c++项目/DM/src/Problem.cpp

CMakeFiles/LaplaceSimulator.dir/src/Problem.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/LaplaceSimulator.dir/src/Problem.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/yifanli/Desktop/M1/c++项目/DM/src/Problem.cpp > CMakeFiles/LaplaceSimulator.dir/src/Problem.cpp.i

CMakeFiles/LaplaceSimulator.dir/src/Problem.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/LaplaceSimulator.dir/src/Problem.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/yifanli/Desktop/M1/c++项目/DM/src/Problem.cpp -o CMakeFiles/LaplaceSimulator.dir/src/Problem.cpp.s

CMakeFiles/LaplaceSimulator.dir/src/Equation.cpp.o: CMakeFiles/LaplaceSimulator.dir/flags.make
CMakeFiles/LaplaceSimulator.dir/src/Equation.cpp.o: /Users/yifanli/Desktop/M1/c++项目/DM/src/Equation.cpp
CMakeFiles/LaplaceSimulator.dir/src/Equation.cpp.o: CMakeFiles/LaplaceSimulator.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/yifanli/Desktop/M1/c++项目/DM/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/LaplaceSimulator.dir/src/Equation.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/LaplaceSimulator.dir/src/Equation.cpp.o -MF CMakeFiles/LaplaceSimulator.dir/src/Equation.cpp.o.d -o CMakeFiles/LaplaceSimulator.dir/src/Equation.cpp.o -c /Users/yifanli/Desktop/M1/c++项目/DM/src/Equation.cpp

CMakeFiles/LaplaceSimulator.dir/src/Equation.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/LaplaceSimulator.dir/src/Equation.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/yifanli/Desktop/M1/c++项目/DM/src/Equation.cpp > CMakeFiles/LaplaceSimulator.dir/src/Equation.cpp.i

CMakeFiles/LaplaceSimulator.dir/src/Equation.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/LaplaceSimulator.dir/src/Equation.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/yifanli/Desktop/M1/c++项目/DM/src/Equation.cpp -o CMakeFiles/LaplaceSimulator.dir/src/Equation.cpp.s

CMakeFiles/LaplaceSimulator.dir/src/Variable.cpp.o: CMakeFiles/LaplaceSimulator.dir/flags.make
CMakeFiles/LaplaceSimulator.dir/src/Variable.cpp.o: /Users/yifanli/Desktop/M1/c++项目/DM/src/Variable.cpp
CMakeFiles/LaplaceSimulator.dir/src/Variable.cpp.o: CMakeFiles/LaplaceSimulator.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/yifanli/Desktop/M1/c++项目/DM/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/LaplaceSimulator.dir/src/Variable.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/LaplaceSimulator.dir/src/Variable.cpp.o -MF CMakeFiles/LaplaceSimulator.dir/src/Variable.cpp.o.d -o CMakeFiles/LaplaceSimulator.dir/src/Variable.cpp.o -c /Users/yifanli/Desktop/M1/c++项目/DM/src/Variable.cpp

CMakeFiles/LaplaceSimulator.dir/src/Variable.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/LaplaceSimulator.dir/src/Variable.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/yifanli/Desktop/M1/c++项目/DM/src/Variable.cpp > CMakeFiles/LaplaceSimulator.dir/src/Variable.cpp.i

CMakeFiles/LaplaceSimulator.dir/src/Variable.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/LaplaceSimulator.dir/src/Variable.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/yifanli/Desktop/M1/c++项目/DM/src/Variable.cpp -o CMakeFiles/LaplaceSimulator.dir/src/Variable.cpp.s

CMakeFiles/LaplaceSimulator.dir/src/UniformMesh.cpp.o: CMakeFiles/LaplaceSimulator.dir/flags.make
CMakeFiles/LaplaceSimulator.dir/src/UniformMesh.cpp.o: /Users/yifanli/Desktop/M1/c++项目/DM/src/UniformMesh.cpp
CMakeFiles/LaplaceSimulator.dir/src/UniformMesh.cpp.o: CMakeFiles/LaplaceSimulator.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/yifanli/Desktop/M1/c++项目/DM/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/LaplaceSimulator.dir/src/UniformMesh.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/LaplaceSimulator.dir/src/UniformMesh.cpp.o -MF CMakeFiles/LaplaceSimulator.dir/src/UniformMesh.cpp.o.d -o CMakeFiles/LaplaceSimulator.dir/src/UniformMesh.cpp.o -c /Users/yifanli/Desktop/M1/c++项目/DM/src/UniformMesh.cpp

CMakeFiles/LaplaceSimulator.dir/src/UniformMesh.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/LaplaceSimulator.dir/src/UniformMesh.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/yifanli/Desktop/M1/c++项目/DM/src/UniformMesh.cpp > CMakeFiles/LaplaceSimulator.dir/src/UniformMesh.cpp.i

CMakeFiles/LaplaceSimulator.dir/src/UniformMesh.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/LaplaceSimulator.dir/src/UniformMesh.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/yifanli/Desktop/M1/c++项目/DM/src/UniformMesh.cpp -o CMakeFiles/LaplaceSimulator.dir/src/UniformMesh.cpp.s

CMakeFiles/LaplaceSimulator.dir/src/NonUniformMesh.cpp.o: CMakeFiles/LaplaceSimulator.dir/flags.make
CMakeFiles/LaplaceSimulator.dir/src/NonUniformMesh.cpp.o: /Users/yifanli/Desktop/M1/c++项目/DM/src/NonUniformMesh.cpp
CMakeFiles/LaplaceSimulator.dir/src/NonUniformMesh.cpp.o: CMakeFiles/LaplaceSimulator.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/yifanli/Desktop/M1/c++项目/DM/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/LaplaceSimulator.dir/src/NonUniformMesh.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/LaplaceSimulator.dir/src/NonUniformMesh.cpp.o -MF CMakeFiles/LaplaceSimulator.dir/src/NonUniformMesh.cpp.o.d -o CMakeFiles/LaplaceSimulator.dir/src/NonUniformMesh.cpp.o -c /Users/yifanli/Desktop/M1/c++项目/DM/src/NonUniformMesh.cpp

CMakeFiles/LaplaceSimulator.dir/src/NonUniformMesh.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/LaplaceSimulator.dir/src/NonUniformMesh.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/yifanli/Desktop/M1/c++项目/DM/src/NonUniformMesh.cpp > CMakeFiles/LaplaceSimulator.dir/src/NonUniformMesh.cpp.i

CMakeFiles/LaplaceSimulator.dir/src/NonUniformMesh.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/LaplaceSimulator.dir/src/NonUniformMesh.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/yifanli/Desktop/M1/c++项目/DM/src/NonUniformMesh.cpp -o CMakeFiles/LaplaceSimulator.dir/src/NonUniformMesh.cpp.s

# Object files for target LaplaceSimulator
LaplaceSimulator_OBJECTS = \
"CMakeFiles/LaplaceSimulator.dir/src/main.cpp.o" \
"CMakeFiles/LaplaceSimulator.dir/src/Problem.cpp.o" \
"CMakeFiles/LaplaceSimulator.dir/src/Equation.cpp.o" \
"CMakeFiles/LaplaceSimulator.dir/src/Variable.cpp.o" \
"CMakeFiles/LaplaceSimulator.dir/src/UniformMesh.cpp.o" \
"CMakeFiles/LaplaceSimulator.dir/src/NonUniformMesh.cpp.o"

# External object files for target LaplaceSimulator
LaplaceSimulator_EXTERNAL_OBJECTS =

LaplaceSimulator: CMakeFiles/LaplaceSimulator.dir/src/main.cpp.o
LaplaceSimulator: CMakeFiles/LaplaceSimulator.dir/src/Problem.cpp.o
LaplaceSimulator: CMakeFiles/LaplaceSimulator.dir/src/Equation.cpp.o
LaplaceSimulator: CMakeFiles/LaplaceSimulator.dir/src/Variable.cpp.o
LaplaceSimulator: CMakeFiles/LaplaceSimulator.dir/src/UniformMesh.cpp.o
LaplaceSimulator: CMakeFiles/LaplaceSimulator.dir/src/NonUniformMesh.cpp.o
LaplaceSimulator: CMakeFiles/LaplaceSimulator.dir/build.make
LaplaceSimulator: CMakeFiles/LaplaceSimulator.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/yifanli/Desktop/M1/c++项目/DM/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking CXX executable LaplaceSimulator"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/LaplaceSimulator.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/LaplaceSimulator.dir/build: LaplaceSimulator
.PHONY : CMakeFiles/LaplaceSimulator.dir/build

CMakeFiles/LaplaceSimulator.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/LaplaceSimulator.dir/cmake_clean.cmake
.PHONY : CMakeFiles/LaplaceSimulator.dir/clean

CMakeFiles/LaplaceSimulator.dir/depend:
	cd /Users/yifanli/Desktop/M1/c++项目/DM/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/yifanli/Desktop/M1/c++项目/DM /Users/yifanli/Desktop/M1/c++项目/DM /Users/yifanli/Desktop/M1/c++项目/DM/build /Users/yifanli/Desktop/M1/c++项目/DM/build /Users/yifanli/Desktop/M1/c++项目/DM/build/CMakeFiles/LaplaceSimulator.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/LaplaceSimulator.dir/depend

