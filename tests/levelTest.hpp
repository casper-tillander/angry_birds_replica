#ifndef LEVELTEST_HPP
#define LEVELTEST_HPP

#include "../src/level.hpp"
#include "../src/bird.hpp"
#include "printer.hpp"

void testAreAllBirdsUsed() {
    sf::RenderWindow mockWindow;

    sf::Texture mockTexture;

    std::string mockLevelFile = "mock_level.txt";

    // Create a Level object for testing
    Level testLevel(mockWindow, 1, mockTexture, mockLevelFile, false, false);

    // Call the setupWorld() method to set up the Box2D world
    testLevel.setupWorld();

    // Add mock objects to the level for testing (you may need to modify this based on your actual implementation)
    testLevel.createFloor();
    testLevel.createBoundaries();
    testLevel.initializeBirds(mockTexture, false);

    // Check if all birds are used (should return false at this point)
    printTestResult(!testLevel.areAllBirdsUsed(), "areAllBirdsUsed (Before Bird Usage)");

    testLevel.nextBird(mockTexture, false);
    testLevel.nextBird(mockTexture, false);
    Bird* bird = testLevel.getCurrentBird();
    bird->launch(b2Vec2(0.0f, 0.0f));

    // Check if all birds are used (should return true since there is only one bird in the level)
    printTestResult(testLevel.areAllBirdsUsed(), "areAllBirdsUsed (After Bird Usage)");

}

#endif