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
include CMakeFiles/AngryBirds.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/AngryBirds.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/AngryBirds.dir/flags.make

CMakeFiles/AngryBirds.dir/src/main.cpp.o: CMakeFiles/AngryBirds.dir/flags.make
CMakeFiles/AngryBirds.dir/src/main.cpp.o: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/caspertillander/cpp-course-autumn-2023/Project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/AngryBirds.dir/src/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/AngryBirds.dir/src/main.cpp.o -c /home/caspertillander/cpp-course-autumn-2023/Project/src/main.cpp

CMakeFiles/AngryBirds.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/AngryBirds.dir/src/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/caspertillander/cpp-course-autumn-2023/Project/src/main.cpp > CMakeFiles/AngryBirds.dir/src/main.cpp.i

CMakeFiles/AngryBirds.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/AngryBirds.dir/src/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/caspertillander/cpp-course-autumn-2023/Project/src/main.cpp -o CMakeFiles/AngryBirds.dir/src/main.cpp.s

# Object files for target AngryBirds
AngryBirds_OBJECTS = \
"CMakeFiles/AngryBirds.dir/src/main.cpp.o"

# External object files for target AngryBirds
AngryBirds_EXTERNAL_OBJECTS =

AngryBirds: CMakeFiles/AngryBirds.dir/src/main.cpp.o
AngryBirds: CMakeFiles/AngryBirds.dir/build.make
AngryBirds: libs/box2d/bin/libbox2d.a
AngryBirds: /usr/lib/x86_64-linux-gnu/libsfml-network.so.2.5.1
AngryBirds: /usr/lib/x86_64-linux-gnu/libsfml-audio.so.2.5.1
AngryBirds: /usr/lib/x86_64-linux-gnu/libsfml-graphics.so.2.5.1
AngryBirds: /usr/lib/x86_64-linux-gnu/libsfml-window.so.2.5.1
AngryBirds: /usr/lib/x86_64-linux-gnu/libsfml-system.so.2.5.1
AngryBirds: CMakeFiles/AngryBirds.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/caspertillander/cpp-course-autumn-2023/Project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable AngryBirds"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/AngryBirds.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/AngryBirds.dir/build: AngryBirds

.PHONY : CMakeFiles/AngryBirds.dir/build

CMakeFiles/AngryBirds.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/AngryBirds.dir/cmake_clean.cmake
.PHONY : CMakeFiles/AngryBirds.dir/clean

CMakeFiles/AngryBirds.dir/depend:
	cd /home/caspertillander/cpp-course-autumn-2023/Project/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/caspertillander/cpp-course-autumn-2023/Project /home/caspertillander/cpp-course-autumn-2023/Project /home/caspertillander/cpp-course-autumn-2023/Project/build /home/caspertillander/cpp-course-autumn-2023/Project/build /home/caspertillander/cpp-course-autumn-2023/Project/build/CMakeFiles/AngryBirds.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/AngryBirds.dir/depend

