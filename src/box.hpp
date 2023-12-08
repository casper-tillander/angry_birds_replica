#ifndef BOX_HPP
#define BOX_HPP

#include <SFML/Graphics.hpp>
#include <box2d/box2d.h>

/**
 * @class Box
 * @brief Represents a box object in the game.
 * 
 * This class manages the rendering and physics of a box.
 */

class Box {
private:
    // Rendering and physics variables
    sf::RectangleShape boxShape; 
    b2Body* body;

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

    b2Body* getBody() const;
    b2Vec2 getPosition() const;
};

#endif // BOX_HPP
