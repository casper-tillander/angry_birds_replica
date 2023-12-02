#ifndef BIRDTEST_HPP
#define BIRDTEST_HPP

#include "../src/bird.hpp"
#include "printer.hpp"

void testBirdConstructor() {
    b2World world(b2Vec2(0.0f, 0.0f));
    sf::Texture texture;
    b2Vec2 initialPosition(0.0f, 0.0f);

    Bird bird(&world, texture, initialPosition);

    // Check initial state
    printTestResult(!bird.isBirdLaunched() && bird.getVelocity() == b2Vec2(0.0f, 0.0f), "BirdConstructor");
}

void testLaunch() {
    b2World world(b2Vec2(0.0f, 0.0f));
    sf::Texture texture;
    b2Vec2 initialPosition(0.0f, 0.0f);

    Bird bird(&world, texture, initialPosition);

    // Check initial state
    printTestResult(!bird.isBirdLaunched(), "Launch (Initial State)");

    bird.launch(b2Vec2(1.0f, 0.0f));

    // Check the state after launch
    printTestResult(bird.isBirdLaunched() && bird.getVelocity() != b2Vec2(0.0f, 0.0f), "Launch (After Launch)");
}

void testCalculateTrajectory() {
    b2World world(b2Vec2(0.0f, 0.0f));
    sf::Texture texture;
    b2Vec2 initialPosition(0.0f, 0.0f);

    Bird bird(&world, texture, initialPosition);

    b2Vec2 launchForce(1.0f, 0.0f);
    bird.launch(launchForce);

    // Calculate the trajectory dots
    std::vector<sf::CircleShape> trajectoryDots = bird.calculateTrajectory(sf::Vector2f(launchForce.x, launchForce.y), 10);

    // Check the number of dots
    printTestResult(trajectoryDots.size() == 10, "CalculateTrajectory (Number of Dots)");
}

#endif