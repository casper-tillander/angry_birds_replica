#include "readfile.hpp"
#include <fstream>
#include <sstream>

std::vector<ObjectData> readLevelData(const std::string& filename) {
    std::vector<ObjectData> objects;
    std::ifstream file(filename);
    std::string line, type;
    float x, y;

    // Skip the first line (headers)
    std::getline(file, line);

    while (std::getline(file, line)) {
        std::istringstream s(line);
        std::getline(s, type, ',');
        s >> x;
        s.ignore(); // Ignore the comma
        s >> y;
        objects.push_back({type, x, y});
    }

    return objects;
}
