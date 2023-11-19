#ifndef GUI_HPP
#define GUI_HPP

#include <SFML/Graphics.hpp>

class GUI {
public:
    GUI();
    void run();

private:
    sf::RenderWindow window;
    sf::Text titleText;
    sf::Text playText;
    sf::CircleShape ButtonShape; // Change to CircleShape
    sf::Text levelsText; // New title for levels screen
    sf::Text level1Text; // New button for Level 1
    sf::Text level2Text; // New button for Level 2
    sf::Text level3Text; // New button for Level 3
    sf::Font font;
    sf::Texture backgroundTexture;
    sf::Sprite backgroundSprite;

    enum Screen { Home, Levels }; // Enum for screen state
    Screen currentScreen; // Variable to hold the current screen state

    void initialize();
    void processEvents();
    void update();
    void render();
    void startGame();
    void drawHomeScreen();
    void drawLevelsScreen();
};

#endif // GUI_HPP
