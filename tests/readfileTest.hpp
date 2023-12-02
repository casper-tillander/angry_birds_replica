#ifndef READTEST_HPP
#define READTEST_HPP

#include "../src/readfile.hpp"
#include "../src/level.hpp"
#include "printer.hpp"
#include <iostream>

void testReadValidFile() {
    const std::string file = "../tests/testfiles/validFile.csv";
    auto result = readLevelData(file);
    // Verify the size and contents of the result vector
    printTestResult(result.size() == 2 && result[0].type == "box" && result[0].x == 1 && result[0].y == 2 &&
                        result[1].type == "box" && result[1].x == 3 && result[1].y == 4,
                    "testReadValidFile");
}

void testReadEmptyFile() {
    std::string filename = "../tests/testfiles/emptyFile.csv";

    std::vector<ObjectData> result = readLevelData(filename);

    // Verify that the result vector is empty
    printTestResult(result.empty(), "testReadEmptyFile");
}

void testReadInvalidData() {
    std::string filename = "../tests/testfiles/invalidFile.csv";

    std::vector<ObjectData> result = readLevelData(filename);

    // Verify that the result vector is smaller than expected due to invalid data
    printTestResult(result.size() == 1 && result[0].type == "wall" && result[0].x == 300 && result[0].y == 40,
                    "testReadInvalidData");
}


#endif