#ifndef PIG_HPP
#define PIG_HPP

#include <SFML/Graphics.hpp>
#include <box2d/box2d.h>

/**
 * @class Pig
 * @brief Represents a pig object in the game.
 */

class Pig {
private:
    // Rendering and physics variables
    sf::CircleShape pigShape; 
    b2Body* body;

    // State variables
    float health;
    bool isAlive;
    bool markedForDeletion;

public:
    /**
     * @brief Constructs a Pig object.
     *
     * @param world Pointer to the Box2D world.
     * @param texture Texture for the pig.
     * @param position Initial position of the pig.
     */
    Pig(b2World* world, const sf::Texture& texture, const b2Vec2& position);

    /**
     * @brief Updates the pig's state.
     */
    void update();

    /**
     * @brief Renders the pig on the given window.
     *
     * @param window The SFML render window.
     */
    void render(sf::RenderWindow& window);

    /**
     * @brief Applies damage to the pig's health.
     *
     * @param damage Amount of damage to apply.
     */
    void takeDamage(float damage);

    /**
     * @brief Checks if the pig is alive.
     *
     * @return true if the pig is alive, false otherwise.
     */
    bool alive() const;

    /**
     * @brief Destroys the Box2D body associated with the pig.
     */
    void destroyBody();

    /**
     * @brief Marks the pig for deletion.
     */
    void markForDeletion();

    /**
     * @brief Checks if the pig is marked for deletion.
     *
     * @return true if marked for deletion, false otherwise.
     */
    bool isMarkedForDeletion() const;

    /**
     * @brief Retrieves the pig's health.
     *
     * @return The current health of the pig.
     */
    float getHealth() const;

    /**
     * @brief Retrieves the Box2D body associated with the pig.
     *
     * @return Pointer to the pig's Box2D body.
     */
    b2Body* getBody() const;
};

#endif // PIG_HPP
