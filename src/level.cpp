#include "level.hpp"

Level::Level(sf::RenderWindow& win, int number, const sf::Texture& birdTex, const sf::Texture& backTex) 
    : levelNumber(number), window(win), world(new b2World(b2Vec2(0.0f, 9.8f))) {
    setupWorld();

    // Set up and scale background
    backgroundTexture = backTex;
    backgroundSprite.setTexture(backgroundTexture);
    sf::Vector2u textureSize = backgroundTexture.getSize();
    sf::Vector2u windowSize = window.getSize();
    float scaleX = static_cast<float>(windowSize.x) / textureSize.x;
    float scaleY = static_cast<float>(windowSize.y) / textureSize.y;
    backgroundSprite.setScale(scaleX, scaleY);

    // Set up bird
    bird = new Bird(world, birdTex, b2Vec2(100.0f, 400.0f));

    // Set up pig
    pigTexture.loadFromFile("../Pictures/pig.png"); // Replace with your texture path
    pig = new Pig(world, pigTexture, b2Vec2(300.0f, 400.0f));
}

Level::~Level() {
    delete bird;
    delete pig;
    delete world;
}

void Level::run() {
    while (window.isOpen()) {
        // Handle events
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            // Call handleInput for the bird
            bird->handleInput(event, window);
        }

        // Update
        world->Step(1.0f/60.0f, 6, 2);
        bird->update();
        pig->update();


        // Render
        window.clear();
        window.draw(backgroundSprite); // Draw the background first
        bird->render(window);
        pig->render(window);
        window.display();
    }
}


void Level::setupWorld() {
    createFloor();
    createBoundaries();
    // Additional world setup can be added here
}

void Level::createBoundaries() {
    float windowWidth = window.getSize().x;
    float windowHeight = window.getSize().y;

    // Create boundaries (left, right, top)
    createBoundary(0, windowHeight / 2, 1, windowHeight); // Left wall
    createBoundary(windowWidth, windowHeight / 2, 1, windowHeight); // Right wall
    createBoundary(windowWidth / 2, 0, windowWidth, 1); // Top wall
}

void Level::createBoundary(float x, float y, float width, float height) {
    b2BodyDef boundaryDef;
    boundaryDef.position.Set(x, y);
    b2Body* boundaryBody = world->CreateBody(&boundaryDef);

    b2PolygonShape boundaryBox;
    boundaryBox.SetAsBox(width / 2, height / 2);
    boundaryBody->CreateFixture(&boundaryBox, 0.0f);
}


void Level::createFloor() {
    // Create a static ground body
    b2BodyDef groundBodyDef;
    groundBodyDef.position.Set(400.0f, 500.0f);
    b2Body* groundBody = world->CreateBody(&groundBodyDef);

    b2PolygonShape groundBox;
    groundBox.SetAsBox(500.0f, 10.0f); // Width and height of the ground
    groundBody->CreateFixture(&groundBox, 0.0f);
}
