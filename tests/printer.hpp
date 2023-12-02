#ifndef PRINTER_HPP
#define PRINTER_HPP

#include <iostream>

int total = 0;
int passed = 0;

void printTestResult(bool condition, const char* testName) {
    if (condition) {
        std::cout << "[PASS] " << testName << std::endl;
        passed++;
    } else {
        std::cout << "[FAIL] " << testName << std::endl;
    }
    total++;
}

void printResults() {
    std::cout << "PASSED " << passed << " out of " << total << " tests!" << std::endl; 
}

#endif