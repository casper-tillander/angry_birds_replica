#ifndef READFILE_HPP
#define READFILE_HPP

#include <string>
#include <vector>

/**
 * @class ObjectData
 * @brief Reads a CSV file that makes up the game levels
 */

struct ObjectData {
    ///< Object type
    std::string type; 
    
    // Coordinates
    float x, y;
};

/**
 * @brief Reads object data from a file and returns a vector of ObjectData.
 *
 * @param filename The name of the file to read.
 * @return A vector of ObjectData representing object properties.
 */
std::vector<ObjectData> readLevelData(const std::string& filename);

#endif // READFILE_HPP

