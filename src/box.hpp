#ifndef BOX_HPP
#define BOX_HPP

#include <SFML/Graphics.hpp>
#include <box2d/box2d.h>

/**
 * @class Box
 * @brief Represents a box object in the game.
 */
class Box {
private:
    sf::Sprite sprite; ///< The box's sprite.
    b2Body* body; ///< The box's Box2D body.

public:
    /**
     * @brief Constructor for the Box class.
     * @param world Pointer to the Box2D world.
     * @param texture The texture for the box.
     * @param position The initial position of the box.
     */
    Box(b2World* world, const sf::Texture& texture, const b2Vec2& position);

    /**
     * @brief Updates the box's state.
     */
    void update();

    /**
     * @brief Renders the box on the provided SFML window.
     * @param window The SFML window to render on.
     */
    void render(sf::RenderWindow& window);
};

#endif // BOX_HPP
