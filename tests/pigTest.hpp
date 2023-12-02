#ifndef PIGTEST_HPP
#define PIGTEST_HPP

#include "../src/pig.hpp"
#include "printer.hpp"

void testPigConstructor() {
    b2World world(b2Vec2(0.0f, 0.0f));
    sf::Texture texture;
    b2Vec2 initialPosition(0.0f, 0.0f);

    Pig pig(&world, texture, initialPosition);

    // Check initial state
    printTestResult(pig.alive() && !pig.isMarkedForDeletion() && pig.getHealth() == 100.0f, "PigConstructor");
}

void testTakeDamage() {
    b2World world(b2Vec2(0.0f, 0.0f));
    sf::Texture texture;
    b2Vec2 initialPosition(0.0f, 0.0f);

    Pig pig(&world, texture, initialPosition);

    // Check initial state
    printTestResult(pig.alive() && !pig.isMarkedForDeletion(), "TakeDamage (Initial State)");

    pig.takeDamage(20.0f);

    // Check the state after damage
    printTestResult(pig.alive() && !pig.isMarkedForDeletion() && pig.getHealth() == 80.0f, "TakeDamage (After Damage)");

    // Apply damage to bring health below zero and mark for deletion
    pig.takeDamage(100.0f);

    // Check the state after fatal damage
    printTestResult(!pig.alive() && pig.isMarkedForDeletion(), "TakeDamage (Fatal Damage)");
}

void testDestroyBody() {
    b2World world(b2Vec2(0.0f, 0.0f));
    sf::Texture texture;
    b2Vec2 initialPosition(0.0f, 0.0f);

    Pig pig(&world, texture, initialPosition);

    // Check initial state
    printTestResult(pig.alive() && !pig.isMarkedForDeletion() && pig.getBody() != nullptr, "DestroyBody (Initial State)");

    pig.destroyBody();
    pig.takeDamage(100.0f);

    // Check the state after body destruction
    printTestResult(!pig.alive() && pig.isMarkedForDeletion() && pig.getBody() == nullptr, "DestroyBody (After Destruction)");
}

#endif