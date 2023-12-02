#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <string>
#include <map>

class Player {
public:
    std::string name;
    std::map<int, int> levelScores; // level number -> stars earned

    Player(std::string name);

    std::string loadFromFile();
    void saveToFile();
    int getScoreForLevel(int levelNumber);
    void updateScore(int levelNumber, int stars);
};

#endif // PLAYER_HPP
