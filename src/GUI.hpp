#ifndef GUI_HPP
#define GUI_HPP

#include <SFML/Graphics.hpp>
#include "level.hpp"
#include "bird.hpp"

/**
 * @class GUI
 * @brief Manages the game's graphical user interface.
 */
class GUI {
public:
    /**
     * @brief Constructs a GUI object.
     */
    GUI();

    /**
     * @brief Runs the game's GUI.
     */
    void run();

private:
    sf::RenderWindow window; ///< The game's window.
    sf::Text titleText; ///< The title text on the screen.
    sf::Text playText; ///< The play button text.
    sf::CircleShape ButtonShape; ///< The circular button shape.
    sf::Text levelsText; ///< The title for the levels screen.
    sf::Text level1Text; ///< The button for Level 1.
    sf::Text level2Text; ///< The button for Level 2.
    sf::Text level3Text; ///< The button for Level 3.
    sf::Text tryAgainText; ///< The button for trying again.
    sf::Text returnToLevelsText; ///< The button for returning to levels.
    sf::Font font; ///< The font used for text.
    sf::Texture backgroundTexture; ///< The background texture.
    sf::Texture levelBackgroundTexture; ///< The background texture for the levels-screen.

    sf::Texture gameOverBackgroundTexture; ///< The background texture for the game over screen.
    sf::Texture levelCompleteBackgroundTexture; ///< The background texture for the level complete screen.

    sf::Sprite backgroundSprite; ///< The background sprite.
    sf::FloatRect buttonBounds; ///< The bounding rectangle for the button.
    sf::Texture birdTexture; ///< The texture for the bird.

    Level* currentLevel;  ///< Pointer to the current level.
    enum Screen { Home, Levels, PlayingLevel, GameOver, LevelCompleted }; ///< Different game screens.
    Screen currentScreen; ///< Variable to hold the current screen state.
    int levelNumber; ///< Variable to hold the current level number.

    /**
     * @brief Initializes the GUI components.
     */
    void initialize();

    /**
     * @brief Processes user input events.
     */
    void processEvents();

    /**
     * @brief Updates the GUI state.
     */
    void update();

    /**
     * @brief Renders the GUI components.
     */
    void render();

    /**
     * @brief Starts the game.
     */
    void startGame();

    /**
     * @brief Draws the home screen.
     */
    void drawHomeScreen();

    /**
     * @brief Draws the levels screen.
     */
    void drawLevelsScreen();

    /**
     * @brief Launches a specific game level.
     *
     * @param levelNumber The number of the level to launch.
     */
    void launchLevel(int levelNumber);


    /**
     * @brief Centers the given text within a button.
     *
     * @param text A reference to the sf::Text object that needs to be centered.
     */

    void drawGameOverScreen();
    void drawLevelCompletedScreen();
    void updateButtonHoverEffect(sf::Text& buttonText, sf::Vector2f mousePos);
    void checkAndUpdateGameState();
};

#endif // GUI_HPP

