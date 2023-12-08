#ifndef SPECIALBIRD_HPP
#define SPECIALBIRD_HPP

#include "bird.hpp"

/**
 * @defgroup SpecialBird SpecialBird
 * @brief Defines the SpecialBird class, a type of Bird with specific shooting behavior.
 */

/**
 * @class SpecialBird
 * @ingroup SpecialBird
 * @brief Represents a special type of bird with specific shooting behavior.
 */

class SpecialBird : public Bird {
public:
    SpecialBird(b2World* world, const sf::Texture& texture, const b2Vec2& position);
     
     /**
     * @brief Handles input events specific to the SpecialBird.
     *
     * @param event The SFML event to handle.
     * @param window The SFML render window.
     */
    void handleInput(const sf::Event& event, const sf::RenderWindow& window) override;

    /**
     * @brief Checks if the SpecialBird has been shot.
     *
     * @return true if the SpecialBird has been shot, false otherwise.
     */
    bool getShot();

private:
    /**
     * @brief Makes the SpecialBird shoot towards the clicked position.
     *
     * @param targetPosition The position clicked by the player.
     */
    void shootTowardsClick(const sf::Vector2f& targetPosition);
    
    bool isShot; ///< @brief Represents whether the SpecialBird has been shot or not
};

#endif // SPECIALBIRD_HPP
