#ifndef LEVEL_HPP
#define LEVEL_HPP

#include <SFML/Graphics.hpp>
#include <box2d/box2d.h>
#include <vector>
#include "bird.hpp"
#include "specialbird.hpp"
#include "pig.hpp"
#include "box.hpp"
#include "wall.hpp"
#include "readfile.hpp"
#include "collisiondetection.hpp"

/**
 * @class Level
 * @brief Represents a game level with physics simulation.
 * 
 * This class manages the elements and behavior of a game level,
 * including Box2D physics simulation, game objects like birds, pigs, boxes, and walls,
 * as well as handling the game's progression and state.
 */

class Level {
private:
    // Level properties
    int levelNumber;
    int currentBirdIndex = 0; 
    int totalBirds = 3; 
    sf::RenderWindow& window;
    sf::Texture backgroundTexture;
    sf::Sprite backgroundSprite; 
    b2World* world;
    bool noGravity;

    // Level objects
    std::vector<Pig*> pigs; 
    std::vector<Box*> boxes;
    std::vector<Wall*> walls;
    std::vector<Bird*> birds;

    //Textures used in class
    sf::Texture pigTexture; 
    sf::Texture boxTexture;
    sf::Texture wallTexture; 
    sf::Texture birdTexture; 
    sf::Font font;

    // UI elements
    sf::Text birdsRemainingText;
    sf::Text pigsRemainingText; 

public:
    /**
     * @brief Constructs a Level object.
     *
     * @param win Reference to the game's window.
     * @param number The level number.
     * @param birdTex The texture for the bird.
     * @param backTex The texture for the background.
     * @param levelFile The path to the level file.
     */
    Level(sf::RenderWindow& win, int number, const sf::Texture& backTex, const std::string& levelFile, bool isSpecialBird, bool noGravity);


    bool isSpecialBird;
    /**
     * @brief Destroys the Level object.
     */
    ~Level();

    /**
     * @brief Runs the game level.
     */
    void run();

    /**
     * @brief Sets up the Box2D world and initializes objects.
     */
    void setupWorld();

    /**
     * @brief Creates the floor of the level.
     */
    void createFloor();

    /**
     * @brief Creates boundaries around the level.
     */
    void createBoundaries();

    /**
     * @brief Creates a boundary in the world.
     *
     * @param x The x-coordinate of the boundary.
     * @param y The y-coordinate of the boundary.
     * @param width The width of the boundary.
     * @param height The height of the boundary.
     */
    void createBoundary(float x, float y, float width, float height);

    /**
     * @brief Loads game objects from a level file.
     *
     * @param levelFile The path to the level file.
     */
    void loadObjects(const std::string& levelFile);

    /**
     * @brief Initializes bird objects.
     *
     * @param birdTex The texture for birds.
     */
    void initializeBirds(const sf::Texture& birdTex, bool isSpecialBird);

    /**
     * @brief Moves to the next bird in the sequence.
     *
     * @param birdTex The texture for birds.
     */
    void nextBird(const sf::Texture& birdTex, bool isSpecialBird);

    /**
     * @brief Checks if the current bird has stopped moving.
     *
     * @return True if the bird has stopped, otherwise false.
     */
    bool hasBirdStopped() const;

    /**
     * @brief Checks if the level is complete.
     *
     * @return True if the level is complete, otherwise false.
     */
    bool isLevelComplete() const;

    /**
     * @brief Checks if the game is over.
     *
     * @return True if the game is over, otherwise false.
     */
    bool isGameOver() const;

    /**
     * @brief Checks if all pigs have been destroyed.
     *
     * @return True if all pigs are destroyed, otherwise false.
     */
    bool areAllPigsDestroyed() const;

    /**
     * @brief Checks if all birds have been used.
     *
     * @return True if all birds are used, otherwise false.
     */
    bool areAllBirdsUsed() const;

    int getBirdsUsedForCompletion();

    Bird* getCurrentBird();

};

#endif // LEVEL_HPP





