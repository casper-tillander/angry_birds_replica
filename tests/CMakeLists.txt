# CMakeLists.txt in the tests folder

set(TEST_EXECUTABLE_NAME AngryBirdsTests)

# Add all test source files in the tests directory
file(GLOB TEST_SOURCES ../tests/*.cpp)

# Link the test executable with the library
add_executable(${TEST_EXECUTABLE_NAME} ${TEST_SOURCES})
target_link_libraries(${TEST_EXECUTABLE_NAME} PRIVATE ${LIBRARY_NAME})

set_target_properties(${TEST_EXECUTABLE_NAME} PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/tests
)

add_test(NAME ${TEST_EXECUTABLE_NAME} COMMAND ${CMAKE_BINARY_DIR}/tests/${TEST_EXECUTABLE_NAME})
