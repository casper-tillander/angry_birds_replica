#include "../src/bird.hpp"
#include "../src/pig.hpp"
#include <iostream>

void printTestResult(bool condition, const char* testName) {
    if (condition) {
        std::cout << "[PASS] " << testName << std::endl;
    } else {
        std::cout << "[FAIL] " << testName << std::endl;
    }
}

void testConstructor() {
    b2World world(b2Vec2(0.0f, 0.0f));
    sf::Texture texture;
    b2Vec2 initialPosition(0.0f, 0.0f);

    Bird bird(&world, texture, initialPosition);

    // Check initial state
    printTestResult(!bird.isBirdLaunched() && bird.getVelocity() == b2Vec2(0.0f, 0.0f), "ConstructorAndInitialState");
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


void testConstructorAndInitialState() {
    b2World world(b2Vec2(0.0f, 0.0f));
    sf::Texture texture;
    b2Vec2 initialPosition(0.0f, 0.0f);

    Pig pig(&world, texture, initialPosition);

    // Check initial state
    printTestResult(pig.alive() && !pig.isMarkedForDeletion() && pig.getHealth() == 100.0f, "ConstructorAndInitialState");
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

int main() {
    testConstructorAndInitialState();
    testTakeDamage();
    testDestroyBody();
    testConstructor();
    testLaunch();
    testCalculateTrajectory();

    return 0;
}
