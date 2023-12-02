#ifndef LEVEL_EDITOR_HPP
#define LEVEL_EDITOR_HPP

#include <SFML/Graphics.hpp>
#include <box2d/box2d.h>

class LevelEditor {
private:
    int levelNumber;
    int chosenObject = 1;
    sf::Text playCreatedLevelText;
    sf::Font font;
    sf::CircleShape ButtonShape;

    sf::RenderWindow& window;
    sf::Texture backgroundTexture;
    sf::Sprite backgroundSprite;

    sf::Texture pigTexture;
    sf::Texture wallTexture;
    sf::Texture boxTexture;

    sf::Sprite pigSprite;
    sf::Sprite wallSprite;
    sf::Sprite boxSprite;

    sf::RectangleShape highlightRectangle;

public:
    LevelEditor(sf::RenderWindow& win, int number, const sf::Texture& backTex);

    void run();



};



#endif // LEVEL_EDITOR_HPP