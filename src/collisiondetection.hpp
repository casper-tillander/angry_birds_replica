#ifndef COLLISIONDETECTION_HPP
#define COLLISIONDETECTION_HPP

#include <box2d/box2d.h>
#include "pig.hpp"
#include "bird.hpp"

/**
 * @class CollisionDetection
 * @brief Handles collision detection and contact events.
 */
class CollisionDetection : public b2ContactListener {
public:
    /**
     * @brief Called when two Box2D fixtures begin contact.
     *
     * @param contact A pointer to the contact object.
     */
    void BeginContact(b2Contact* contact) override;

private:
    /**
     * @brief Calculate the impact damage of a collision.
     *
     * @param contact A pointer to the contact object.
     * @return The calculated impact damage.
     */
    float CalculateImpactDamage(b2Contact* contact); // Declare this method
};

#endif // COLLISIONDETECTION_HPP


