# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.27

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
CMAKE_COMMAND = /Applications/CMake.app/Contents/bin/cmake

# The command to remove a file.
RM = /Applications/CMake.app/Contents/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/linsku/c++fall2023/Project

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/linsku/c++fall2023/Project/build

# Include any dependencies generated for this target.
include libs/box2d/extern/glad/CMakeFiles/glad.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include libs/box2d/extern/glad/CMakeFiles/glad.dir/compiler_depend.make

# Include the progress variables for this target.
include libs/box2d/extern/glad/CMakeFiles/glad.dir/progress.make

# Include the compile flags for this target's objects.
include libs/box2d/extern/glad/CMakeFiles/glad.dir/flags.make

libs/box2d/extern/glad/CMakeFiles/glad.dir/src/gl.c.o: libs/box2d/extern/glad/CMakeFiles/glad.dir/flags.make
libs/box2d/extern/glad/CMakeFiles/glad.dir/src/gl.c.o: /Users/linsku/c++fall2023/Project/libs/box2d/extern/glad/src/gl.c
libs/box2d/extern/glad/CMakeFiles/glad.dir/src/gl.c.o: libs/box2d/extern/glad/CMakeFiles/glad.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/linsku/c++fall2023/Project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object libs/box2d/extern/glad/CMakeFiles/glad.dir/src/gl.c.o"
	cd /Users/linsku/c++fall2023/Project/build/libs/box2d/extern/glad && /usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT libs/box2d/extern/glad/CMakeFiles/glad.dir/src/gl.c.o -MF CMakeFiles/glad.dir/src/gl.c.o.d -o CMakeFiles/glad.dir/src/gl.c.o -c /Users/linsku/c++fall2023/Project/libs/box2d/extern/glad/src/gl.c

libs/box2d/extern/glad/CMakeFiles/glad.dir/src/gl.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/glad.dir/src/gl.c.i"
	cd /Users/linsku/c++fall2023/Project/build/libs/box2d/extern/glad && /usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/linsku/c++fall2023/Project/libs/box2d/extern/glad/src/gl.c > CMakeFiles/glad.dir/src/gl.c.i

libs/box2d/extern/glad/CMakeFiles/glad.dir/src/gl.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/glad.dir/src/gl.c.s"
	cd /Users/linsku/c++fall2023/Project/build/libs/box2d/extern/glad && /usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/linsku/c++fall2023/Project/libs/box2d/extern/glad/src/gl.c -o CMakeFiles/glad.dir/src/gl.c.s

# Object files for target glad
glad_OBJECTS = \
"CMakeFiles/glad.dir/src/gl.c.o"

# External object files for target glad
glad_EXTERNAL_OBJECTS =

libs/box2d/bin/libglad.a: libs/box2d/extern/glad/CMakeFiles/glad.dir/src/gl.c.o
libs/box2d/bin/libglad.a: libs/box2d/extern/glad/CMakeFiles/glad.dir/build.make
libs/box2d/bin/libglad.a: libs/box2d/extern/glad/CMakeFiles/glad.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/linsku/c++fall2023/Project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C static library ../../bin/libglad.a"
	cd /Users/linsku/c++fall2023/Project/build/libs/box2d/extern/glad && $(CMAKE_COMMAND) -P CMakeFiles/glad.dir/cmake_clean_target.cmake
	cd /Users/linsku/c++fall2023/Project/build/libs/box2d/extern/glad && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/glad.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
libs/box2d/extern/glad/CMakeFiles/glad.dir/build: libs/box2d/bin/libglad.a
.PHONY : libs/box2d/extern/glad/CMakeFiles/glad.dir/build

libs/box2d/extern/glad/CMakeFiles/glad.dir/clean:
	cd /Users/linsku/c++fall2023/Project/build/libs/box2d/extern/glad && $(CMAKE_COMMAND) -P CMakeFiles/glad.dir/cmake_clean.cmake
.PHONY : libs/box2d/extern/glad/CMakeFiles/glad.dir/clean

libs/box2d/extern/glad/CMakeFiles/glad.dir/depend:
	cd /Users/linsku/c++fall2023/Project/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/linsku/c++fall2023/Project /Users/linsku/c++fall2023/Project/libs/box2d/extern/glad /Users/linsku/c++fall2023/Project/build /Users/linsku/c++fall2023/Project/build/libs/box2d/extern/glad /Users/linsku/c++fall2023/Project/build/libs/box2d/extern/glad/CMakeFiles/glad.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : libs/box2d/extern/glad/CMakeFiles/glad.dir/depend

