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
Level::Level(sf::RenderWindow& win, int number, const sf::Texture& birdTex, const sf::Texture& backTex, const std::string& levelFile) 
    : levelNumber(number), window(win), world(new b2World(b2Vec2(0.0f, 9.8f))) {
    setupWorld();

    backgroundTexture = backTex;
    backgroundSprite.setTexture(backgroundTexture);
    sf::Vector2u textureSize = backgroundTexture.getSize();
    sf::Vector2u windowSize = window.getSize();
    float scaleX = static_cast<float>(windowSize.x) / textureSize.x;
    float scaleY = static_cast<float>(windowSize.y) / textureSize.y;
    backgroundSprite.setScale(scaleX, scaleY);

    bird = new Bird(world, birdTex, b2Vec2(100.0f, 500.0f));

    pigTexture.loadFromFile("../Pictures/pig.png");
    boxTexture.loadFromFile("../Pictures/box.jpg");
    wallTexture.loadFromFile("../Pictures/wall.jpg");

    loadObjects(levelFile);

    auto collisionDetection = new CollisionDetection();
    world->SetContactListener(collisionDetection);
}

/**
 * @brief Destroys the Level object.
 */
Level::~Level() {
    delete bird;
    for (auto pig : pigs) delete pig;
    for (auto box : boxes) delete box;
    for (auto wall : walls) delete wall;
    delete world;
}

/**
 * @brief Runs the game level.
 */
void Level::run() {
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            bird->handleInput(event, window);
        }

        world->Step(1.0f/60.0f, 6, 2);
        bird->update();

        for (auto pig : pigs) pig->update();
        for (auto box : boxes) box->update();
        for (auto wall : walls) wall->update();

        window.clear();
        window.draw(backgroundSprite);
        bird->render(window);

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
    groundBodyDef.position.Set(400.0f, 600.0f);
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

