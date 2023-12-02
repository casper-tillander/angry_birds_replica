#include "collisiondetection.hpp"

bool CollisionDetection::isBirdFixture(b2Fixture* fixture) {
    if (fixture == nullptr) {
        return false;
    }

    return fixture->GetDensity() == 0.99f;
}




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


