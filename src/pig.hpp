#ifndef PIG_HPP
#define PIG_HPP

#include <SFML/Graphics.hpp>
#include <box2d/box2d.h>

class Pig {
private:
    sf::Sprite sprite;
    b2Body* body;

public:
    Pig(b2World* world, const sf::Texture& texture, const b2Vec2& position);
    void update();
    void render(sf::RenderWindow& window);
};

#endif // PIG_HPP
