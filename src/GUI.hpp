#ifndef GUI_HPP
#define GUI_HPP

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "level.hpp"
#include "bird.hpp"
#include "leveleditor.hpp"
#include "player.hpp"

/**
 * @class GUI
 * @brief Manages the game's graphical user interface.
 */
class GUI {
public:
    GUI(); // Constructor
    void run(); // Runs the game's GUI

    // Public members
    bool isSpecialBird;
    int selectedBackground;

private:
    // Private members
    // Textures
    sf::Texture mainScreenTexture; ///< The background texture.
    sf::Texture backgroundTexture;
    sf::Texture soundTexture;
    sf::Texture levelBackgroundTexture; ///< The background texture for the levels-screen.
    sf::Texture settingsBackgroundTexture; ///< The background texture for the settings-screen.
    sf::Texture editorBackgroundTexture; ///< The background texture for choosing level for level editor.
    sf::Texture gameOverBackgroundTexture; ///< The background texture for the game over screen.
    sf::Texture levelCompleteBackgroundTexture; ///< The background texture for the level complete screen.
    sf::Texture chooseABirdBackgroundTexture;
    sf::Texture birdTexture; ///< The texture for the bird.
    sf::Texture specialBirdTexture; ///< The texture for the special bird.
    sf::Texture levelEditor1; ///< The texture for level 1.
    sf::Texture levelEditor2; ///< The texture for level 2.
    sf::Texture levelEditor3; ///< The texture for level 3.
    sf::Texture starTexture;

    // Fonts
    sf::Font font; ///< The font used for text.

    // RenderWindow
    sf::RenderWindow window; ///< The game's window.

    // Music
    sf::Music music;

    // Texts
    sf::Text titleText; ///< The title text on the screen.
    sf::Text playText; ///< The play button text.
    sf::Text settingsText; ///< The settings button text.
    sf::Text returnToHomeText; ///< The home button text.
    sf::Text levelsText; ///< The title for the levels screen.
    sf::Text level1Text; ///< The button for Level 1.
    sf::Text level2Text; ///< The button for Level 2.
    sf::Text level3Text; ///< The button for Level 3.
    sf::Text tryAgainText; ///< The button for trying again.
    sf::Text returnToLevelsText; ///< The button for returning to levels.
    sf::Text createLevelText; ///< The text for the button to launch the level editor.
    sf::Text gravityText;
    sf::Text playerMessage;
    sf::Text chooseBirdText; ///< The text for the button to choose a bird.
    sf::Text levelEditorText;
    sf::Text playerNameLabel;
    sf::Text submitButtonText;
    sf::Text inputText;

    // Shapes and Buttons
    sf::CircleShape ButtonShape; ///< The circular button shape.
    sf::CircleShape highlightCircle; ///< The circle to highlight the selected bird.
    sf::CircleShape circleButton;
    sf::RectangleShape highlightRectangle; ///< The rectangle to highlight the selected background.
    sf::RectangleShape redLine;
    sf::RectangleShape redLine2;
    sf::RectangleShape playerNameInputBox;
    sf::RectangleShape submitButton;

    // Sprites
    sf::Sprite backgroundSprite; ///< The background sprite.
    sf::Sprite soundButton;
    sf::Sprite normalBirdButton; ///< Button for choosing the normal bird.
    sf::Sprite specialBirdButton; ///< Button for choosing the special bird.
    sf::Sprite starSprite;
    sf::Sprite levelStarSprite;
    sf::Sprite level1Button; ///< Button for choosing level 1 for level editor.
    sf::Sprite level2Button; ///< Button for choosing level 2 for level editor.
    sf::Sprite level3Button; ///< Button for choosing level 3 for level editor.

    // Game State Variables
    Level* currentLevel; ///< Pointer to the current level.
    enum Screen { Home, BirdSelection, Levels, PlayingLevel, GameOver, LevelCompleted, Settings, LevelEditorSelection, PlayingLevelEditor }; ///< Different game screens.
    Screen currentScreen; ///< Variable to hold the current screen state.
    int levelNumberEditor;
    LevelEditor* currentLevelEditor;
    std::string pathToCreatedFile;
    Player* currentPlayer;
    std::string playerNameInput;

    // Additional int and bool members
    int levelNumber; ///< Variable to hold the current level number.
    sf::Vector2u textureSize; ///< Variable to hold the size of the texture.
    sf::Vector2u windowSize; ///< Variable to hold the size of the window.
    bool soundOn;
    bool noGravity;
    bool isLevelEditorLevel;

    // Private member functions
    void initialize(); // Initializes the GUI components.
    void processEvents(); // Processes user input events.
    void update(); // Updates the GUI state.
    void render(); // Renders the GUI components.
    void startGame(); // Starts the game.
    void drawHomeScreen(); // Draws the home screen.
    void drawLevelsScreen(); // Draws the levels screen.
    void launchLevel(int levelNumber); // Launches a specific game level.
    void drawGameOverScreen(); // Draws the game over screen.
    void drawLevelCompletedScreen(); // Draws the level completed screen.
    void updateButtonHoverEffect(sf::Text& buttonText, sf::Vector2f mousePos); // Updates the button hover effect.
    void drawSettingsScreen(); // Draws the settings screen.
    void setupButton(sf::Text& buttonText, const std::string& text); // Sets up the buttons.
    void updateBackground(); // Updates the background
    void drawBirdSelectionScreen();
    void drawLevelEditorSelectionScreen();
    void launchLevelEditor(int levelNumberEditor);
    void launchLevelEditorLevel(int levelNumberEditor, std::string filePath);
};

#endif // GUI_HPP
