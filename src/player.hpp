#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <string>
#include <map>

/**
 * @class Player
 * @brief Represents a player in the game, storing their name and level scores.
 */

class Player {
public:
    // Player name
    std::string name;

    /**
     * @defgroup LevelProperties Level Properties
     * @{
     */
    std::map<int, int> levelScores; 

    /**
     * @brief Constructs a Player object.
     *
     * @param name The name of the player.
     */
    Player(std::string name);
    
    /**
     * @brief Loads player data from a file.
     *
     * @return Message indicating the player status.
     */
    std::string loadFromFile();

     /**
     * @brief Saves player data to a file.
     */
    void saveToFile();

    /**
     * @brief Gets the score earned by the player for a specific level.
     *
     * @param levelNumber The level number.
     * @return The score earned by the player for the specified level.
     */
    int getScoreForLevel(int levelNumber);

    /**
     * @brief Updates the score for a specific level if it's higher than the previous score.
     *
     * @param levelNumber The number of the level.
     * @param stars The number of stars earned.
     */
    void updateScore(int levelNumber, int stars);
};

#endif // PLAYER_HPP
