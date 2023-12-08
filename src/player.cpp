#include "player.hpp"
#include <fstream>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <cctype>

Player::Player(std::string name) {
    std::transform(name.begin(), name.end(), name.begin(), 
                   [](unsigned char c){ return std::toupper(c); });
    this->name = name;
}

/**
 * @brief Loads player data from a file.
 *
 * @return A message indicating whether the player is new or existing.
 */
std::string Player::loadFromFile() {
    std::string filePath = "../Players/" + name + ".csv";
    std::string message;
    std::ifstream file(filePath);
    if (file.is_open()) {
        std::string line;
        while (std::getline(file, line)) {
            std::stringstream ss(line);
            int levelNumber, stars;
            ss >> levelNumber >> stars;
            levelScores[levelNumber] = stars;
        }
        file.close();
        message = "Playing as " + name;
    } else {
        // File doesn't exist, which is fine for a new player
        message = "New player: " + name;
    }
    return message;
}

/**
 * @brief Saves player data to a file.
 */
void Player::saveToFile() {
    std::string filePath = "../Players/" + name + ".csv";
    std::ofstream file(filePath);
    if (file.is_open()) {
        for (const auto &pair : levelScores) {
            file << pair.first << " " << pair.second << std::endl;
        }
        file.close();
    } else {
        std::cerr << "Unable to open file for saving player data" << std::endl;
    }
}

/**
 * @brief Retrieves the score for a specific level.
 *
 * @param levelNumber The number of the level.
 * @return The score earned by the player for that level.
 */
int Player::getScoreForLevel(int levelNumber) {
    if (levelScores.find(levelNumber) != levelScores.end()) {
        return levelScores[levelNumber];
    } else {
        return 0; // Default score if the player hasn't played this level yet
    }
}

/**
 * @brief Updates the score for a specific level if it's higher than the previous score.
 *
 * @param levelNumber The number of the level.
 * @param stars The number of stars earned.
 */
void Player::updateScore(int levelNumber, int stars) {
    if (levelScores.find(levelNumber) == levelScores.end() || levelScores[levelNumber] < stars) {
        levelScores[levelNumber] = stars;
    }
}
