#ifndef LEVEL_HPP
#define LEVEL_HPP

#include <SFML/Graphics.hpp>
#include <box2d/box2d.h>
#include <vector>
#include "bird.hpp"
#include "pig.hpp"
#include "box.hpp"
#include "wall.hpp"
#include "readfile.hpp"

class Level {
private:
    int levelNumber;
    sf::RenderWindow& window;
    sf::Texture backgroundTexture;
    sf::Sprite backgroundSprite;
    b2World* world;
    Bird* bird;
    std::vector<Pig*> pigs;
    std::vector<Box*> boxes;
    std::vector<Wall*> walls;
    sf::Texture pigTexture;
    sf::Texture boxTexture;
    sf::Texture wallTexture;

public:
    Level(sf::RenderWindow& win, int number, const sf::Texture& birdTex, const sf::Texture& backTex, const std::string& levelFile);
    ~Level();
    void run();
    void setupWorld();
    void createFloor();
    void createBoundaries();
    void createBoundary(float x, float y, float width, float height);
    void loadObjects(const std::string& levelFile);
};

#endif // LEVEL_HPP



