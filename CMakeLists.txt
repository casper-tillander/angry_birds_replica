cmake_minimum_required(VERSION 3.0)

project(AngryBirds)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories("src")

# Create a library containing the source code
set(LIBRARY_NAME AngryBirdsLib)
file(GLOB LIBRARY_SOURCES src/*.cpp)
add_library(${LIBRARY_NAME} ${LIBRARY_SOURCES})

# Set the name of the main executable
set(EXECUTABLE_NAME AngryBirds)
add_executable(${EXECUTABLE_NAME} src/main.cpp)

# Link the main executable with the library
target_link_libraries(${EXECUTABLE_NAME} PRIVATE ${LIBRARY_NAME})

# Add the Box2D library
add_subdirectory(libs/box2d)
include_directories(${CMAKE_SOURCE_DIR}/libs/box2d/include)
target_link_libraries(${LIBRARY_NAME} PRIVATE box2d)

# Detect and add SFML
find_package(SFML 2 COMPONENTS network audio graphics window system REQUIRED)
if(SFML_FOUND)
  target_link_libraries(${LIBRARY_NAME} PRIVATE sfml-network sfml-audio sfml-graphics sfml-window sfml-system)
endif()

# For installing targets (not mandatory)
install(TARGETS ${EXECUTABLE_NAME} DESTINATION bin)

# Add tests
add_subdirectory(tests)
