#ifndef GAME_HPP
#define GAME_HPP

#include "GUI.hpp"

/**
 * @class Game
 * @brief Represents the main game control.
 *
 * The Game class manages the overall control flow and execution of the game.
 * It initializes the game components, such as the graphical user interface (GUI),
 * and runs the main game loop.
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
    GUI gui;
};

#endif // GAME_HPP
