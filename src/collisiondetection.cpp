#include "collisiondetection.hpp"

/**
 * @brief Called when two Box2D fixtures begin contact.
 *
 * @param contact A pointer to the contact object.
 */
void CollisionDetection::BeginContact(b2Contact* contact) {

    b2Fixture* fixtureA = contact->GetFixtureA();
    b2Fixture* fixtureB = contact->GetFixtureB();

    Pig* pigA = reinterpret_cast<Pig*>(fixtureA->GetBody()->GetUserData().pointer);
    Pig* pigB = reinterpret_cast<Pig*>(fixtureB->GetBody()->GetUserData().pointer);

    float damage = CalculateImpactDamage(contact);

    if (pigA != nullptr) {
        pigA->takeDamage(damage);
    }
    if (pigB != nullptr) {
        pigB->takeDamage(damage);
    }
}

/**
 * @brief Calculate the impact damage of a collision.
 *
 * @param contact A pointer to the contact object.
 * @return The calculated impact damage.
 */
float CollisionDetection::CalculateImpactDamage(b2Contact* contact) {
    // TODO: Implement damage logic
    // Idea: Use contact->GetManifold() to calculate the damage
    return 10.0f; // Placeholder value
}

