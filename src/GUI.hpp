#ifndef GUI_HPP
#define GUI_HPP

#include <SFML/Graphics.hpp>

class GUI {
public:
    GUI();
    ~GUI();
    void run();

private:
    sf::RenderWindow window;
    sf::Font font;
    sf::Text titleText;
    sf::Text playButton;
    sf::Text exitButton;
    sf::Text levelText;

    // Additional UI elements can be added here

    void initWindow();
    void initUI();
    void handleEvents();
    void update();
    void render();
};

#endif

