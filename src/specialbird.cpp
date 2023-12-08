#include "specialbird.hpp"

/**
 * @brief Constructs a SpecialBird object.
 *
 * @param world Pointer to the Box2D world.
 * @param texture The texture for the special bird.
 * @param position The initial position of the special bird.
 */

SpecialBird::SpecialBird(b2World* world, const sf::Texture& texture, const b2Vec2& position)
: Bird(world, texture, position) {
    isShot = false;
}

/**
 * @brief Handles input events for the SpecialBird.
 *
 * Overrides the base class function to handle specific input for the SpecialBird.
 *
 * @param event The SFML event to handle.
 * @param window The SFML render window.
 */
void SpecialBird::handleInput(const sf::Event& event, const sf::RenderWindow& window) {
    Bird::handleInput(event, window);

    if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
        sf::Vector2f clickPosition = window.mapPixelToCoords(sf::Mouse::getPosition(window));
        shootTowardsClick(clickPosition);
    }
}

/**
 * @brief Makes the SpecialBird shoot towards the clicked position.
 *
 * @param targetPosition The position clicked by the player.
 */
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

/**
 * @brief Checks if the SpecialBird has been shot.
 *
 * @return true if the SpecialBird has been shot, false otherwise.
 */
bool SpecialBird::getShot() {
    return isShot;
}