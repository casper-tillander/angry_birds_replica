#ifndef WALL_HPP
#define WALL_HPP

#include <SFML/Graphics.hpp>
#include <box2d/box2d.h>

/**
 * @brief Represents a wall object in the game.
 *
 * This class defines a wall object that can be used in the game. It includes
 * methods for updating and rendering the wall.
 */
class Wall {
private:
    sf::RectangleShape wallShape; ///< The wall's shape for rendering.
    b2Body* body; ///< The Box2D body associated with the wall.

public:
    /**
     * @brief Constructs a wall object.
     *
     * @param world A pointer to the Box2D world.
     * @param texture The texture to be used for the wall sprite.
     * @param position The initial position of the wall.
     */
    Wall(b2World* world, const sf::Texture& texture, const b2Vec2& position);

    /**
     * @brief Updates the wall's position and state.
     */
    void update();

    /**
     * @brief Renders the wall on the specified window.
     *
     * @param window The rendering window to draw the wall on.
     */
    void render(sf::RenderWindow& window);

    /**
     * @brief Gets the Box2D body associated with the wall.
    *
    * @return A pointer to the Box2D body.
    */
    b2Body* getBody() const;


    /**
    * @brief Gets the position of the wall.
    *
    * @return The position of the wall in the Box2D world.
    */
    b2Vec2 getPosition() const;
};

#endif // WALL_HPP

