#ifndef SPECIALTEST_HPP
#define SPECIALTEST_HPP

#include "../src/specialbird.hpp"
#include "printer.hpp"

void testSpecialBirdConstructor() {
    b2World world(b2Vec2(0.0f, 0.0f));
    sf::Texture texture;
    b2Vec2 initialPosition(0.0f, 0.0f);

    SpecialBird specialBird(&world, texture, initialPosition);

    // Check initial state
    printTestResult(!specialBird.isBirdLaunched() && specialBird.getVelocity() == b2Vec2(0.0f, 0.0f), "SpecialBirdConstructorAndInitialState");
}

void testSpecialBirdShootTowardsClick() {
    b2World world(b2Vec2(0.0f, 0.0f));
    sf::Texture texture;
    b2Vec2 initialPosition(0.0f, 0.0f);

    SpecialBird specialBird(&world, texture, initialPosition);

    // Simulate a launch for the special bird
    specialBird.launch(b2Vec2(1.0f, 0.0f));

    // Simulate a click event at (200, 200) on the window
    sf::Event clickEvent;
    clickEvent.type = sf::Event::MouseButtonPressed;
    clickEvent.mouseButton.x = 200;
    clickEvent.mouseButton.y = 200;

    sf::RenderWindow window; // Assuming a valid window instance

    // Handle the click event, which should trigger shooting towards the click
    specialBird.handleInput(clickEvent, window);

    // Check if the bird is marked as shot after handling the click event
    printTestResult(specialBird.getShot(), "SpecialBirdShootTowardsClick (Bird is Shot)");

    // Check if the bird's velocity has changed after handling the click event
    b2Vec2 initialVelocity = specialBird.getVelocity();
    specialBird.update();  // Assuming update is called to apply changes
    b2Vec2 finalVelocity = specialBird.getVelocity();
    printTestResult(specialBird.isBirdLaunched() && initialVelocity != finalVelocity, "SpecialBirdShootTowardsClick (Bird Velocity Changed)");

}

#endif