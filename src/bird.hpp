#ifndef BIRD_HPP
#define BIRD_HPP

#include <SFML/Graphics.hpp>
#include <box2d/box2d.h>

class Bird {
private:
    sf::Sprite sprite;
    b2Body* body;
    bool isLaunched;
    bool isDragging;
    sf::Vector2f initialClickPosition;
    const float FORCE_MULTIPLIER = 10000.0f;  // Adjust this value as needed

public:
    Bird(b2World* world, const sf::Texture& texture, const b2Vec2& position);
    void update();
    void render(sf::RenderWindow& window);
    void handleInput(const sf::Event& event, const sf::RenderWindow& window);
    void launch(const b2Vec2& force);
};

#endif // BIRD_HPP