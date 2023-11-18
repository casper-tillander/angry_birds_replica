cmake_minimum_required(VERSION 3.0)  # Minimum CMake version recommended

project(AngryBirds)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories("src")

# Set the name of the executable to be produced
set(EXECUTABLE_NAME AngryBirds)

# Add all .cpp files under src/ directory
file(GLOB SOURCES src/*.cpp)
add_executable(${EXECUTABLE_NAME} ${SOURCES})
set(CMAKE_BUILD_TYPE Debug)

# Add the Box2D library
add_subdirectory(libs/box2d)
include_directories(${CMAKE_SOURCE_DIR}/libs/box2d/include)
target_link_libraries(${EXECUTABLE_NAME} PRIVATE box2d)

# Detect and add SFML
find_package(SFML 2 COMPONENTS network audio graphics window system REQUIRED)
if(SFML_FOUND)
  target_link_libraries(${EXECUTABLE_NAME} PRIVATE sfml-network sfml-audio sfml-graphics sfml-window sfml-system)
endif()

# For installing targets (not mandatory)
install(TARGETS ${EXECUTABLE_NAME} DESTINATION bin)



