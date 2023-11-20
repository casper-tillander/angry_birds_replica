#ifndef BOX_HPP
#define BOX_HPP

#include <SFML/Graphics.hpp>
#include <box2d/box2d.h>

class Box {
private:
    sf::Sprite sprite;
    b2Body* body;

public:
    Box(b2World* world, const sf::Texture& texture, const b2Vec2& position);
    void update();
    void render(sf::RenderWindow& window);
};

#endif // BOX_HPP