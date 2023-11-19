#ifndef LEVEL_HPP
#define LEVEL_HPP

#include <SFML/Graphics.hpp>
#include <box2d/box2d.h>
#include "bird.hpp"
#include "pig.hpp"

class Level {
private:
    int levelNumber;
    sf::RenderWindow& window;
    sf::Texture backgroundTexture;
    sf::Sprite backgroundSprite;
    b2World* world;
    Bird* bird;
    Pig* pig;
    sf::Texture pigTexture;
    sf::Event event;

public:
    Level(sf::RenderWindow& win, int number, const sf::Texture& birdTex, const sf::Texture& backTex);
    ~Level();
    void run();
    void setupWorld();
    void createFloor();
    void createBoundaries(); // Corrected the function name
    void createBoundary(float x, float y, float width, float height); // Added parameters
};

#endif // LEVEL_HPP


