#ifndef GAME_HPP
#define GAME_HPP

#include "GUI.hpp"

/**
 * @class Game
 * @brief Represents the main game control.
 */
class Game {

public:
    /**
     * @brief Constructs a Game object.
     */
    Game();

    /**
     * @brief Runs the game loop.
     */
    void run();

private:
    GUI gui; ///< The graphical user interface for the game.
};

#endif // GAME_HPP
