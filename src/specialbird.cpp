#include "specialbird.hpp"

SpecialBird::SpecialBird(b2World* world, const sf::Texture& texture, const b2Vec2& position)
: Bird(world, texture, position) {
    isShot = false;
}

void SpecialBird::handleInput(const sf::Event& event, const sf::RenderWindow& window) {
    Bird::handleInput(event, window);

    if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
        sf::Vector2f clickPosition = window.mapPixelToCoords(sf::Mouse::getPosition(window));
        shootTowardsClick(clickPosition);
    }
}

void SpecialBird::shootTowardsClick(const sf::Vector2f& targetPosition) {
    b2Vec2 currentPosition = body->GetPosition();
    b2Vec2 target(targetPosition.x, targetPosition.y);
    
    if (isBirdLaunched() && !isShot) {
        // Calculate direction and normalize it
        b2Vec2 direction = target - currentPosition;
        direction.Normalize();

        // Set velocity or apply force
        float velocityMagnitude = 300.0f;
        body->SetLinearVelocity(velocityMagnitude * direction);

        isShot = true;
    }
}
