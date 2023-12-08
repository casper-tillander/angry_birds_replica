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
 *
 * The GUI class handles the rendering and interaction components of the game's user interface.
 * It manages various textures, fonts, window settings, buttons, game state variables, and screens.
 * This class processes user input, updates GUI states, and renders GUI components for different screens.
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
    sf::Texture mainScreenTexture;
    sf::Texture backgroundTexture;
    sf::Texture soundTexture;
    sf::Texture levelBackgroundTexture;
    sf::Texture settingsBackgroundTexture; 
    sf::Texture editorBackgroundTexture; 
    sf::Texture gameOverBackgroundTexture; 
    sf::Texture levelCompleteBackgroundTexture;
    sf::Texture chooseABirdBackgroundTexture;
    sf::Texture birdTexture;
    sf::Texture specialBirdTexture;
    sf::Texture levelEditor1;
    sf::Texture levelEditor2;
    sf::Texture levelEditor3; 
    sf::Texture starTexture;

    // Fonts
    sf::Font font; 

    // RenderWindow
    sf::RenderWindow window;

    // Music
    sf::Music music;

    // Texts
    sf::Text titleText; 
    sf::Text playText; 
    sf::Text settingsText; 
    sf::Text returnToHomeText; 
    sf::Text levelsText; 
    sf::Text level1Text;
    sf::Text level2Text; 
    sf::Text level3Text; 
    sf::Text tryAgainText; 
    sf::Text returnToLevelsText; 
    sf::Text createLevelText; 
    sf::Text gravityText;
    sf::Text playerMessage;
    sf::Text chooseBirdText;
    sf::Text levelEditorText;
    sf::Text playerNameLabel;
    sf::Text submitButtonText;
    sf::Text inputText;

    // Shapes and Buttons
    sf::CircleShape ButtonShape; 
    sf::CircleShape highlightCircle;
    sf::CircleShape circleButton;
    sf::RectangleShape highlightRectangle; 
    sf::RectangleShape redLine;
    sf::RectangleShape redLine2;
    sf::RectangleShape playerNameInputBox;
    sf::RectangleShape submitButton;

    // Sprites
    sf::Sprite backgroundSprite; 
    sf::Sprite soundButton;
    sf::Sprite normalBirdButton; 
    sf::Sprite specialBirdButton; 
    sf::Sprite starSprite;
    sf::Sprite levelStarSprite;
    sf::Sprite level1Button; 
    sf::Sprite level2Button; 
    sf::Sprite level3Button;

    // Game State Variables
    Level* currentLevel; 
    enum Screen { Home, BirdSelection, Levels, PlayingLevel, GameOver, LevelCompleted, Settings, LevelEditorSelection, PlayingLevelEditor }; ///< Different game screens.
    Screen currentScreen; 
    int levelNumberEditor;
    LevelEditor* currentLevelEditor;
    std::string pathToCreatedFile;
    Player* currentPlayer;
    std::string playerNameInput;

    // Additional int and bool members
    int levelNumber; 
    sf::Vector2u textureSize; 
    sf::Vector2u windowSize; 
    bool soundOn;
    bool noGravity;
    bool isLevelEditorLevel;

    // Private member functions
    void initialize(); 
    void processEvents(); 
    void update(); 
    void render(); 
    void startGame(); 
    void drawHomeScreen(); 
    void drawLevelsScreen(); 
    void launchLevel(int levelNumber); 
    void drawGameOverScreen(); 
    void drawLevelCompletedScreen(); 
    void updateButtonHoverEffect(sf::Text& buttonText, sf::Vector2f mousePos); 
    void drawSettingsScreen(); 
    void setupButton(sf::Text& buttonText, const std::string& text);
    void updateBackground(); 
    void drawBirdSelectionScreen();
    void drawLevelEditorSelectionScreen();
    void launchLevelEditor(int levelNumberEditor);
    void launchLevelEditorLevel(int levelNumberEditor, std::string filePath);
};

#endif // GUI_HPP
