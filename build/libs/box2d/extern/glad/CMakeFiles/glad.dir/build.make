# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/caspertillander/cpp-course-autumn-2023/Project

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/caspertillander/cpp-course-autumn-2023/Project/build

# Include any dependencies generated for this target.
include libs/box2d/extern/glad/CMakeFiles/glad.dir/depend.make

# Include the progress variables for this target.
include libs/box2d/extern/glad/CMakeFiles/glad.dir/progress.make

# Include the compile flags for this target's objects.
include libs/box2d/extern/glad/CMakeFiles/glad.dir/flags.make

libs/box2d/extern/glad/CMakeFiles/glad.dir/src/gl.c.o: libs/box2d/extern/glad/CMakeFiles/glad.dir/flags.make
libs/box2d/extern/glad/CMakeFiles/glad.dir/src/gl.c.o: ../libs/box2d/extern/glad/src/gl.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/caspertillander/cpp-course-autumn-2023/Project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object libs/box2d/extern/glad/CMakeFiles/glad.dir/src/gl.c.o"
	cd /home/caspertillander/cpp-course-autumn-2023/Project/build/libs/box2d/extern/glad && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/glad.dir/src/gl.c.o   -c /home/caspertillander/cpp-course-autumn-2023/Project/libs/box2d/extern/glad/src/gl.c

libs/box2d/extern/glad/CMakeFiles/glad.dir/src/gl.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/glad.dir/src/gl.c.i"
	cd /home/caspertillander/cpp-course-autumn-2023/Project/build/libs/box2d/extern/glad && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/caspertillander/cpp-course-autumn-2023/Project/libs/box2d/extern/glad/src/gl.c > CMakeFiles/glad.dir/src/gl.c.i

libs/box2d/extern/glad/CMakeFiles/glad.dir/src/gl.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/glad.dir/src/gl.c.s"
	cd /home/caspertillander/cpp-course-autumn-2023/Project/build/libs/box2d/extern/glad && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/caspertillander/cpp-course-autumn-2023/Project/libs/box2d/extern/glad/src/gl.c -o CMakeFiles/glad.dir/src/gl.c.s

# Object files for target glad
glad_OBJECTS = \
"CMakeFiles/glad.dir/src/gl.c.o"

# External object files for target glad
glad_EXTERNAL_OBJECTS =

libs/box2d/bin/libglad.a: libs/box2d/extern/glad/CMakeFiles/glad.dir/src/gl.c.o
libs/box2d/bin/libglad.a: libs/box2d/extern/glad/CMakeFiles/glad.dir/build.make
libs/box2d/bin/libglad.a: libs/box2d/extern/glad/CMakeFiles/glad.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/caspertillander/cpp-course-autumn-2023/Project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C static library ../../bin/libglad.a"
	cd /home/caspertillander/cpp-course-autumn-2023/Project/build/libs/box2d/extern/glad && $(CMAKE_COMMAND) -P CMakeFiles/glad.dir/cmake_clean_target.cmake
	cd /home/caspertillander/cpp-course-autumn-2023/Project/build/libs/box2d/extern/glad && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/glad.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
libs/box2d/extern/glad/CMakeFiles/glad.dir/build: libs/box2d/bin/libglad.a

.PHONY : libs/box2d/extern/glad/CMakeFiles/glad.dir/build

libs/box2d/extern/glad/CMakeFiles/glad.dir/clean:
	cd /home/caspertillander/cpp-course-autumn-2023/Project/build/libs/box2d/extern/glad && $(CMAKE_COMMAND) -P CMakeFiles/glad.dir/cmake_clean.cmake
.PHONY : libs/box2d/extern/glad/CMakeFiles/glad.dir/clean

libs/box2d/extern/glad/CMakeFiles/glad.dir/depend:
	cd /home/caspertillander/cpp-course-autumn-2023/Project/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/caspertillander/cpp-course-autumn-2023/Project /home/caspertillander/cpp-course-autumn-2023/Project/libs/box2d/extern/glad /home/caspertillander/cpp-course-autumn-2023/Project/build /home/caspertillander/cpp-course-autumn-2023/Project/build/libs/box2d/extern/glad /home/caspertillander/cpp-course-autumn-2023/Project/build/libs/box2d/extern/glad/CMakeFiles/glad.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : libs/box2d/extern/glad/CMakeFiles/glad.dir/depend

