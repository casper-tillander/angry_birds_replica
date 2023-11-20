#ifndef WALL_HPP
#define WALL_HPP

#include <SFML/Graphics.hpp>
#include <box2d/box2d.h>

class Wall {
private:
    sf::Sprite sprite;
    b2Body* body;

public:
    Wall(b2World* world, const sf::Texture& texture, const b2Vec2& position);
    void update();
    void render(sf::RenderWindow& window);

};

#endif // WALL_HPP
