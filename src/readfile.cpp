#include "readfile.hpp"
#include <fstream>
#include <sstream>

/**
 * @brief Reads object data from a CSV file and returns a vector of ObjectData.
 *
 * This function reads object data from a CSV file where each line represents an object
 * with a type, x-coordinate, and y-coordinate. It parses the file and constructs
 * a vector of ObjectData structures based on the data.
 *
 * @param filename The name of the CSV file to read.
 * @return A vector of ObjectData representing object properties.
 */
std::vector<ObjectData> readLevelData(const std::string& filename) {
    std::vector<ObjectData> objects;
    std::ifstream file(filename);
    std::string line, type;
    float x, y;

    std::getline(file, line); 

    while (std::getline(file, line)) {
        std::istringstream s(line);
        std::getline(s, type, ',');
        s >> x;
        s.ignore();
        s >> y;
        objects.push_back({type, x, y});
    }

    return objects;
}

