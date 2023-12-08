#include "collisiondetection.hpp"

/**
 * @brief Checks if the given fixture belongs to a bird.
 *
 * @param fixture A pointer to the Box2D fixture.
 * @return True if the fixture belongs to a bird, otherwise false.
 */

bool CollisionDetection::isBirdFixture(b2Fixture* fixture) {
    if (fixture == nullptr) {
        return false;
    }

    return fixture->GetDensity() == 0.99f;
}

/**
 * @brief Handles the beginning of contact between two Box2D fixtures.
 *
 * This function identifies the fixtures involved in the contact and determines
 * the type of entities (pig or bird) interacting, adjusting their health accordingly.
 *
 * @param contact A pointer to the contact object.
 */

void CollisionDetection::BeginContact(b2Contact* contact) {
    b2Fixture* fixtureA = contact->GetFixtureA();
    b2Fixture* fixtureB = contact->GetFixtureB();

    Pig* pigA = reinterpret_cast<Pig*>(fixtureA->GetBody()->GetUserData().pointer);
    Pig* pigB = reinterpret_cast<Pig*>(fixtureB->GetBody()->GetUserData().pointer);

    bool isBirdA = isBirdFixture(fixtureA);
    bool isBirdB = isBirdFixture(fixtureB);

    if (pigA != nullptr) {
        if (isBirdB) {
            pigA->takeDamage(100.0f);
        } else {
            pigA->takeDamage(20.0f);
        }
    }

    if (pigB != nullptr) {
        if (isBirdA) {
            pigB->takeDamage(100.0f);
        } else {
            pigB->takeDamage(20.0f);
        }
    }
}


