#ifndef WALLTEST_HPP
#define WALLTEST_HPP

#include "../src/wall.hpp"
#include "printer.hpp"

void testWallConstructor() {
    b2World world(b2Vec2(0.0f, 0.0f));
    sf::Texture texture;
    b2Vec2 initialPosition(1.0f, 2.0f);

    Wall wall(&world, texture, initialPosition);
    
    // Check that the position matches
    b2Vec2 wallPosition = wall.getBody()->GetPosition();
    printTestResult(wallPosition.x == initialPosition.x && wallPosition.y == initialPosition.y,
                    "Wall Constructor");
}

// Test case 2: Check if the Wall update function updates the position correctly
void testWallUpdate() {
    b2World world(b2Vec2(0.0f, 0.0f));
    sf::Texture texture;
    b2Vec2 initialPosition(1.0f, 2.0f);

    Wall wall(&world, texture, initialPosition);

    wall.update();

    // Check if the Wall position matches the Box2D body position
    b2Vec2 wallPosition = wall.getPosition();
    printTestResult(wall.getPosition().x == wallPosition.x && wall.getPosition().y == wallPosition.y,
                    "Wall Update");
}

#endif