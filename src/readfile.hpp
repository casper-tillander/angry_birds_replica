#ifndef READFILE_HPP
#define READFILE_HPP

#include <string>
#include <vector>

struct ObjectData {
    std::string type;
    float x, y;
};

std::vector<ObjectData> readLevelData(const std::string& filename);

#endif // READFILE_HPP
