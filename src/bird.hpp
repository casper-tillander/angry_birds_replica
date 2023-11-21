#ifndef BIRD_HPP
#define BIRD_HPP

#include <SFML/Graphics.hpp>
#include <box2d/box2d.h>

/**
 * @class Bird
 * @brief Represents a bird object in the game.
 */
class Bird {
private:
    sf::Sprite sprite; ///< The bird's sprite.
    b2Body* body; ///< The bird's Box2D body.
    bool isLaunched; ///< Indicates whether the bird has been launched.
    bool isDragging; ///< Indicates whether the bird is being dragged.
    sf::Vector2f initialClickPosition; ///< The initial click position when dragging.
    const float FORCE_MULTIPLIER = 10000.0f; ///< Multiplier for launch force. Adjust as needed.

public:
    /**
     * @brief Constructor for the Bird class.
     * @param world Pointer to the Box2D world.
     * @param texture The texture for the bird.
     * @param position The initial position of the bird.
     */
    Bird(b2World* world, const sf::Texture& texture, const b2Vec2& position);

    /**
     * @brief Updates the bird's state.
     */
    void update();

    /**
     * @brief Renders the bird on the provided SFML window.
     * @param window The SFML window to render on.
     */
    void render(sf::RenderWindow& window);

    /**
     * @brief Handles input events for the bird.
     * @param event The SFML event to handle.
     * @param window The SFML window associated with the event.
     */
    void handleInput(const sf::Event& event, const sf::RenderWindow& window);

    /**
     * @brief Launches the bird with a specified force.
     * @param force The force vector to apply for the launch.
     */
    void launch(const b2Vec2& force);
};

#endif // BIRD_HPP
