#ifndef BIRD_HPP
#define BIRD_HPP

#include <SFML/Graphics.hpp>
#include <box2d/box2d.h>

class Bird {
private:
    sf::Sprite sprite;
    b2Body* body;
    bool isLaunched;
    sf::Vector2f initialClickPosition; // Store the initial click position
    bool isBeingDragged; // Track if the bird is being dragged

public:
    Bird(b2World* world, const sf::Texture& texture, const b2Vec2& position);
    void update();
    void render(sf::RenderWindow& window);
    void handleInput(const sf::Vector2f& mousePosition, const sf::Event& event);
    void launch(const b2Vec2& force);
};

#endif // BIRD_HPP