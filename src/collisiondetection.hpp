#ifndef COLLISIONDETECTION_HPP
#define COLLISIONDETECTION_HPP

#include <box2d/box2d.h>
#include "pig.hpp"
#include "bird.hpp"

/**
 * @class CollisionDetection
 * @brief Handles collision detection and contact events.
 * 
 * This class extends b2ContactListener to manage collision detection and contact events
 * between Box2D fixtures, specifically handling interactions between pigs and birds.
 */

class CollisionDetection : public b2ContactListener {
public:
    /**
     * @brief Called when two Box2D fixtures begin contact.
     *
     * @param contact A pointer to the contact object.
     */
    void BeginContact(b2Contact* contact) override;
    
      /**
     * @brief Checks if the fixture belongs to a bird.
     *
     * @param fixture A pointer to the Box2D fixture to check.
     * @return True if the fixture belongs to a bird, otherwise false.
     */
    bool isBirdFixture(b2Fixture* fixture);
};

#endif // COLLISIONDETECTION_HPP


