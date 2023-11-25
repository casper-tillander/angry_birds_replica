#include "collisiondetection.hpp"
#include <iostream>

bool isBirdFixture(b2Fixture* fixture) {
    return (fixture->GetUserData().pointer % 2) == 1;
}

/**
 * @brief Called when two Box2D fixtures begin contact.
 *
 * @param contact A pointer to the contact object.
 */
void CollisionDetection::BeginContact(b2Contact* contact) {

    b2Fixture* fixtureA = contact->GetFixtureA();
    b2Fixture* fixtureB = contact->GetFixtureB();

    Pig* pigB = reinterpret_cast<Pig*>(fixtureB->GetBody()->GetUserData().pointer);
    Pig* pigA = reinterpret_cast<Pig*>(fixtureA->GetBody()->GetUserData().pointer);
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
    b2Manifold* manifold = contact->GetManifold();

    // Get the number of contact points
    int numPoints = manifold->pointCount;

    if (numPoints > 0) {
        // Get the normal vector of the first contact point
        b2Vec2 normal = manifold->localNormal;

        // Get the relative velocity of the two colliding bodies
        b2Vec2 relativeVelocity1 = contact->GetFixtureA()->GetBody()->GetLinearVelocity();
        b2Vec2 relativeVelocity2 = contact->GetFixtureB()->GetBody()->GetLinearVelocity();
        float speed1 = relativeVelocity1.Length();
        float speed2 = relativeVelocity2.Length();

        // Calculate the impulse, which is a measure of the impact force
        float impulse = (speed1 > speed2) ? b2Dot(normal, relativeVelocity1) : b2Dot(normal, relativeVelocity2);

        // Take the absolute value of the impulse
        impulse = std::abs(impulse);

        float damage = impulse * 0.8f; // Adjust the multiplier as needed

        // Ensure damage is non-negative
        damage = std::max(0.0f, damage);

        return damage;
    }
    return 0.0f;
}

