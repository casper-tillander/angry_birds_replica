#ifndef GUI_HPP
#define GUI_HPP

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "level.hpp"
#include "bird.hpp"
#include "leveleditor.hpp"

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

    bool isSpecialBird;
    int selectedBackground;

private:

    sf::RenderWindow window; ///< The game's window.
    sf::Music music;
    sf::Text titleText; ///< The title text on the screen.
    sf::Text playText; ///< The play button text.
    sf::Text settingsText; ///< The settings button text.
    sf::Text returnToHomeText; ///< The home button text.
    sf::CircleShape ButtonShape; ///< The circular button shape.
    sf::Text levelsText; ///< The title for the levels screen.
    sf::Text level1Text; ///< The button for Level 1.
    sf::Text level2Text; ///< The button for Level 2.
    sf::Text level3Text; ///< The button for Level 3.
    sf::Text tryAgainText; ///< The button for trying again.
    sf::Text returnToLevelsText; ///< The button for returning to levels.
    sf::Font font; ///< The font used for text.
    sf::Texture mainScreenTexture; ///< The background texture.
    sf::Texture backgroundTexture;
    sf::Texture soundTexture;
    sf::Texture levelBackgroundTexture; ///< The background texture for the levels-screen.
    sf::Texture settingsBackgroundTexture; ///< The background texture for the settings-screen.
    sf::Texture editorBackgroundTexture; ///< The background texture for choosing level for level editor.

    sf::Texture gameOverBackgroundTexture; ///< The background texture for the game over screen.
    sf::Texture levelCompleteBackgroundTexture; ///< The background texture for the level complete screen.
    sf::Texture chooseABirdBackgroundTexture;

    sf::Sprite backgroundSprite; ///< The background sprite.
    sf::FloatRect buttonBounds; ///< The bounding rectangle for the button.
    sf::Texture birdTexture; ///< The texture for the bird.
    sf::Texture specialBirdTexture; ///< The texture for the special bird.
    sf::CircleShape highlightCircle; ///< The circle to highlight the selected bird.

    sf::Text createLevelText; ///< The text for the button to launch the level editor.
    sf::Texture levelEditor1; ///< The texture for level 1.
    sf::Texture levelEditor2; ///< The texture for level 2.
    sf::Texture levelEditor3; ///< The texture for level 3.
    sf::RectangleShape highlightRectangle; ///< The rectangle to highlight the selected background.

    Level* currentLevel;  ///< Pointer to the current level.
    enum Screen { Home, BirdSelection, Levels, PlayingLevel, GameOver, LevelCompleted, Settings, LevelEditorSelection, PlayingLevelEditor }; ///< Different game screens.
    Screen currentScreen; ///< Variable to hold the current screen state.
    int levelNumber; ///< Variable to hold the current level number.

    sf::Vector2u textureSize; ///< Variable to hold the size of the texture..
    sf::Vector2u windowSize; ///< Variable to hold the size of the window.

    sf::Sprite soundButton;
    sf::RectangleShape redLine;
    bool soundOn;

    bool noGravity;
    sf::CircleShape circleButton;
    sf::RectangleShape redLine2;
    sf::Text gravityText;


    sf::Text chooseBirdText; ///< The text for the button to choose a bird.
    sf::Sprite normalBirdButton; ///< Button for choosing the normal bird.
    sf::Sprite specialBirdButton; ///< Button for choosing the special bird.

    sf::Texture starTexture;
    sf::Sprite starSprite;

    sf::Text levelEditorText;
    sf::Sprite level1Button; ///< Button for choosing level 1 for level editor.
    sf::Sprite level2Button; ///< Button for choosing level 2 for level editor.
    sf::Sprite level3Button; ///< Button for choosing level 3 for level editor.
    int levelNumberEditor;
    LevelEditor* currentLevelEditor;
    std::string pathToCreatedFile;
    
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
     * @brief Draws the game over screen.
     */
    void drawGameOverScreen();

    /**
     * @brief Draws the level completed screen.
     */
    void drawLevelCompletedScreen();

    /**
     * @brief Updates the button hover effect.
     *
     * @param buttonText The text of the button.
     * @param mousePos The current mouse position.
     */
    void updateButtonHoverEffect(sf::Text& buttonText, sf::Vector2f mousePos);

    /**
     * @brief Draws the settings screen.
     */
    void drawSettingsScreen();

    /**
     * @brief Sets up the buttons.
     */
    void setupButton(sf::Text& buttonText, const std::string& text);

    /**
     * @brief Updates the background
     */
    void updateBackground();

    void drawBirdSelectionScreen();

    void drawLevelEditorSelectionScreen();

    void launchLevelEditor(int levelNumberEditor);

    void launchLevelEditorLevel(int levelNumberEditor, std::string filePath);

};

#endif // GUI_HPP
