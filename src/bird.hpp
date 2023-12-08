#ifndef BIRD_HPP
#define BIRD_HPP

#include <SFML/Graphics.hpp>
#include <box2d/box2d.h>
#include <vector>

/**
 * @class Bird
 * @brief Represents a bird object in the game.
 *
 * The Bird class encapsulates the properties and behaviors of a bird in the game environment. 
 * It integrates both the rendering and physics aspects of the bird.
 * 
 * This class manages the bird's shape, Box2D body, launch mechanism, input handling for dragging,
 * rendering on an SFML window, updating its position and rotation, as well as calculating and storing
 * trajectory dots used for aiming before launch.
 *
 * The bird can be launched with a specified force and its behavior is governed by Box2D physics,
 * including velocity, collision, and movement in the game world.
 *
 * It maintains states such as whether the bird has been launched or is currently being dragged.
 * The number of birds per level and the index of the current bird are also managed within this class.
 */

class Bird {
private:
    // Textures used in class
    sf::CircleShape birdShape; 

    // State variables
    bool isLaunched; 
    bool isDragging; 
    sf::Vector2f initialClickPosition;
    
    // Constants
    const float FORCE_MULTIPLIER = 200.0f; 
    int currentBirdIndex = 0; 
    int totalBirds = 3; 

public:
    b2Body* body; ///< The bird's Box2D body.
    
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
    virtual void handleInput(const sf::Event& event, const sf::RenderWindow& window);

    /**
     * @brief Launches the bird with a specified force.
     * @param force The force vector to apply for the launch.
     */
    void launch(const b2Vec2& force);

    /**
     * @brief Get the current velocity of the bird.
     * @return The velocity vector of the bird.
     */
    b2Vec2 getVelocity() const;

    /**
     * @brief Check if the bird has been launched.
     * @return True if the bird has been launched, otherwise false.
     */
    bool isBirdLaunched() const;

    /**
     * @brief Get the Box2D body of the bird.
     * @return A pointer to the Box2D body of the bird.
     */
    b2Body* getBody() const;

    std::vector<sf::CircleShape> calculateTrajectory(const sf::Vector2f& launchVector, int numDots);
    std::vector<sf::CircleShape> trajectoryDots; ///< Stores the trajectory dots.
};

#endif // BIRD_HPP
