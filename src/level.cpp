#include "level.hpp"

/**
 * @brief Constructs a Level object.
 *
 * @param win Reference to the game's window.
 * @param number The level number.
 * @param birdTex The texture for the bird.
 * @param backTex The texture for the background.
 * @param levelFile The path to the level file.
 */
Level::Level(sf::RenderWindow& win, int number, const sf::Texture& backTex, const std::string& levelFile, bool isSpecialBirdParam, bool noGravity)
    : levelNumber(number), window(win), world(new b2World(b2Vec2(0.0f, noGravity ? 1.0f : 9.8f))), isSpecialBird(isSpecialBirdParam), noGravity(noGravity) {
    setupWorld();

    backgroundTexture = backTex;
    backgroundSprite.setTexture(backgroundTexture);
    sf::Vector2u textureSize = backgroundTexture.getSize();
    sf::Vector2u windowSize = window.getSize();
    float scaleX = static_cast<float>(windowSize.x) / textureSize.x;
    float scaleY = static_cast<float>(windowSize.y) / textureSize.y;
    backgroundSprite.setScale(scaleX, scaleY);

    if (isSpecialBird) {
        birdTexture.loadFromFile("../Pictures/specialbird.png");
    } else {
        birdTexture.loadFromFile("../Pictures/bird.png");
    }
    
    
    initializeBirds(birdTexture, isSpecialBird);

    pigTexture.loadFromFile("../Pictures/pig.png");
    boxTexture.loadFromFile("../Pictures/box.jpg");
    wallTexture.loadFromFile("../Pictures/wall.jpg");

    loadObjects(levelFile);

    auto collisionDetection = new CollisionDetection();
    world->SetContactListener(collisionDetection);
    
    font.loadFromFile("../Fonts/FEASFBRG.TTF");
    birdsRemainingText.setFont(font);
    birdsRemainingText.setCharacterSize(16);
    birdsRemainingText.setFillColor(sf::Color::White);
    birdsRemainingText.setPosition(10, 10);

    pigsRemainingText.setFont(font);
    pigsRemainingText.setCharacterSize(16);
    pigsRemainingText.setFillColor(sf::Color::White);
    pigsRemainingText.setPosition(10, 30);
}

/**
 * @brief Destroys the Level object.
 */
Level::~Level() {
    for (auto bird : birds) delete bird;
    for (auto pig : pigs) delete pig;
    for (auto box : boxes) delete box;
    for (auto wall : walls) delete wall;
    delete world;
}

/**
 * @brief Runs the game level.
 */
void Level::run() {
    bool shouldExit = false;
    while (window.isOpen() && !shouldExit) {
        sf::Event event;
        while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            window.close();
        else if (currentBirdIndex < birds.size()) {
            Bird* currentBird = birds[currentBirdIndex];
            currentBird->handleInput(event, window);

            if (hasBirdStopped()) {
                nextBird(birdTexture, isSpecialBird);
            }
        }
    }

        world->Step(1.0f/60.0f, 6, 2);

        birds[currentBirdIndex]->update();
        for (auto pig : pigs) pig->update();
        for (auto box : boxes) box->update();
        for (auto wall : walls) wall->update();

        window.clear();
        window.draw(backgroundSprite);
        window.setFramerateLimit(250);

        Bird* currentB = birds[currentBirdIndex];
        if (!currentB->isBirdLaunched()) {
            birdsRemainingText.setString("Birds Remaining: " + std::to_string(totalBirds - currentBirdIndex));
        } else {
            birdsRemainingText.setString("Birds Remaining: " + std::to_string(totalBirds - currentBirdIndex - 1));
        };
        pigsRemainingText.setString("Pigs Remaining: " + std::to_string(pigs.size()));

        window.draw(birdsRemainingText);
        window.draw(pigsRemainingText);
        
        for (int i = 0; i <= currentBirdIndex; ++i) {
            birds[i]->render(window);
        }
        for (auto pig : pigs) pig->render(window);
        for (auto box : boxes) box->render(window);
        for (auto wall : walls) wall->render(window);
        window.display();

        for (auto it = pigs.begin(); it != pigs.end();) {
            if ((*it)->isMarkedForDeletion()) {
                (*it)->destroyBody();
                delete *it;
                it = pigs.erase(it);
            } else {
                ++it;
            }

        if (isLevelComplete()) {
            shouldExit = true;
            break;
        }

        if (isGameOver()) {
            shouldExit = true;
            break;
        }
        }
    }
}

/**
 * @brief Sets up the Box2D world and initializes objects.
 */
void Level::setupWorld() {
    createFloor();
    createBoundaries();
}

/**
 * @brief Creates boundaries around the level.
 */
void Level::createBoundaries() {
    float windowWidth = window.getSize().x;
    float windowHeight = window.getSize().y;

    createBoundary(0, windowHeight / 2, 1, windowHeight);
    createBoundary(windowWidth, windowHeight / 2, 1, windowHeight);
    createBoundary(windowWidth / 2, 0, windowWidth, 1);
}

/**
 * @brief Creates a boundary in the world.
 *
 * @param x The x-coordinate of the boundary.
 * @param y The y-coordinate of the boundary.
 * @param width The width of the boundary.
 * @param height The height of the boundary.
 */
void Level::createBoundary(float x, float y, float width, float height) {
    b2BodyDef boundaryDef;
    boundaryDef.position.Set(x, y);
    b2Body* boundaryBody = world->CreateBody(&boundaryDef);

    b2PolygonShape boundaryBox;
    boundaryBox.SetAsBox(width / 2, height / 2);
    boundaryBody->CreateFixture(&boundaryBox, 0.0f);
}

/**
 * @brief Creates the floor of the level.
 */
void Level::createFloor() {
    b2BodyDef groundBodyDef;
    groundBodyDef.position.Set(400.0f, 650.0f);
    b2Body* groundBody = world->CreateBody(&groundBodyDef);

    b2PolygonShape groundBox;
    groundBox.SetAsBox(1200, 10.0f);
    groundBody->CreateFixture(&groundBox, 0.0f);
}

/**
 * @brief Loads game objects from a level file.
 *
 * @param levelFile The path to the level file.
 */
void Level::loadObjects(const std::string& levelFile) {
    auto objects = readLevelData(levelFile);

    for (const auto& obj : objects) {
        if (obj.type == "pig") {
            pigs.push_back(new Pig(world, pigTexture, b2Vec2(obj.x, obj.y)));
        } else if (obj.type == "box") {
            boxes.push_back(new Box(world, boxTexture, b2Vec2(obj.x, obj.y)));
        } else if (obj.type == "wall") {
            walls.push_back(new Wall(world, wallTexture, b2Vec2(obj.x, obj.y)));
        }
    }
}


/**
 * @brief Initializes the bird objects for the level.
 *
 * @param birdTex The texture for the birds.
 */
void Level::initializeBirds(const sf::Texture& birdTex, bool isSpecialBird) {
    Bird* newBird = nullptr;

    if (totalBirds > 0) {
        if (isSpecialBird) {
            newBird = new SpecialBird(world, birdTex, b2Vec2(100.0f, 500.0f));
        } else {
            newBird = new Bird(world, birdTex, b2Vec2(100.0f, 500.0f));
        }
        
        birds.push_back(newBird);
    }
}


/**
 * @brief Moves to the next bird in the level.
 *
 * @param birdTex The texture for the birds.
 */
void Level::nextBird(const sf::Texture& birdTex, bool isSpecialBird) {
    Bird* newBird = nullptr;

    if (currentBirdIndex < totalBirds - 1) {
        currentBirdIndex++;

        if (isSpecialBird) {
            newBird = new SpecialBird(world, birdTex, b2Vec2(100.0f, 500.0f));
        } else {
            newBird = new Bird(world, birdTex, b2Vec2(100.0f, 500.0f));
        }

        birds.push_back(newBird);
    }
}

/**
 * @brief Checks if the current bird has stopped moving.
 *
 * @return True if the bird has stopped, false otherwise.
 */
bool Level::hasBirdStopped() const {
    if (birds.empty() || currentBirdIndex >= birds.size()) {
        return false;
    }

    Bird* currentBird = birds[currentBirdIndex];
    if (!currentBird->isBirdLaunched()) {
        return false;
    }
    float velocityThreshold = 10.0f;
    if (noGravity) {
        velocityThreshold = 20.0f;
    }
    b2Vec2 velocity = currentBird->getVelocity();
    return std::abs(velocity.x) < velocityThreshold && std::abs(velocity.y) < velocityThreshold;
}

/**
 * @brief Checks if the level is complete.
 *
 * @return True if the level is complete, false otherwise.
 */
bool Level::isLevelComplete() const {
    if (pigs.empty() || (currentBirdIndex == totalBirds - 1 && hasBirdStopped())) {
        return true;
    }
    return false;
}

/**
 * @brief Checks if the game is over.
 *
 * @return True if the game is over, false otherwise.
 */
bool Level::isGameOver() const {
    return areAllBirdsUsed() && !areAllPigsDestroyed();
}

/**
 * @brief Checks if all pigs in the level have been destroyed.
 *
 * @return True if all pigs are destroyed, false otherwise.
 */
bool Level::areAllPigsDestroyed() const {
    return std::all_of(pigs.begin(), pigs.end(), [](const Pig* pig) {
        return !pig->alive();
    });
}

/**
 * @brief Checks if all birds in the level have been used and stopped.
 *
 * @return True if all birds are used and stopped, false otherwise.
 */
bool Level::areAllBirdsUsed() const {
    return currentBirdIndex >= totalBirds - 1 && hasBirdStopped();
}

/**
 * @brief Gets the number of birds used to complete the level.
 * @return The number of birds used if the level is completed, otherwise -1.
 */
int Level::getBirdsUsedForCompletion() {
    if (isLevelComplete()) {
        return currentBirdIndex + 1; 
    } else {
        return -1;
    }
}

Bird* Level::getCurrentBird() {
    return birds[currentBirdIndex];
}