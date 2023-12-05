#ifndef READTEST_HPP
#define READTEST_HPP

#include "../src/readfile.hpp"
#include "printer.hpp"
#include <iostream>
#include <fstream>
#include <cstdio>

void testReadFile() {
    std::ofstream testFile("validFile.csv");
    testFile << "type,x,y\n";
    testFile << "wall,300,40\n";
    testFile.close();
    auto result = readLevelData("validFile.csv");

    // Verify the size and contents of the result vector
    printTestResult(result.size() == 1 && result[0].type == "wall" && result[0].x == 300 && result[0].y == 40,
                    "testReadValidData");
    std::remove("validFile.csv");
}

void testReadEmptyFile() {
    std::ofstream testFile("emptyFile.csv");
    testFile << "type,x,y\n";
    testFile.close();

    auto result = readLevelData("emptyFile.csv");

    // Verify that the result vector is empty
    printTestResult(result.empty(), "testReadEmptyFile");
    std::remove("emptyFile.csv");
}


#endif