#ifndef BOXTEST_HPP
#define BOXTEST_HPP

#include "../src/box.hpp"
#include "printer.hpp"

void testBoxConstructor() {
    b2World world(b2Vec2(0.0f, 0.0f));
    sf::Texture texture;
    b2Vec2 initialPosition(1.0f, 2.0f);

    Box box(&world, texture, initialPosition);

    // Check that the position matches
    b2Vec2 boxPosition = box.getBody()->GetPosition();
    printTestResult(boxPosition.x == initialPosition.x && boxPosition.y == initialPosition.y,
                    "Box Constructor");
}

void testBoxUpdate() {
    b2World world(b2Vec2(0.0f, 0.0f));
    sf::Texture texture;
    b2Vec2 initialPosition(1.0f, 2.0f);

    Box box(&world, texture, initialPosition);

    box.update();

    // Check if the Box position matches the Box2D body position
    b2Vec2 boxPosition = box.getBody()->GetPosition();
    printTestResult(box.getPosition().x == boxPosition.x && box.getPosition().y == boxPosition.y,
                    "Box Update");
}

#endif