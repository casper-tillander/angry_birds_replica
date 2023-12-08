#include "bird.hpp"
#include <iostream>

/**
 * @brief Constructs a Bird object.
 *
 * @param world Pointer to the Box2D world.
 * @param texture The texture for the bird.
 * @param position The initial position of the bird.
 */
Bird::Bird(b2World* world, const sf::Texture& texture, const b2Vec2& position) {
    isLaunched = false;

    birdShape.setRadius(25.0f); 
    birdShape.setTexture(&texture);
    birdShape.setOrigin(birdShape.getRadius(), birdShape.getRadius());

    b2BodyDef bodyDef;
    bodyDef.type = b2_dynamicBody;
    bodyDef.position = position;
    bodyDef.gravityScale = 0.0f;
    bodyDef.angularDamping = 1.0f; 
    bodyDef.fixedRotation = false; 
    body = world->CreateBody(&bodyDef);

    b2CircleShape circleShape;
    circleShape.m_radius = 10.0f; 

    b2FixtureDef fixtureDef;
    fixtureDef.shape = &circleShape;
    fixtureDef.density = 0.99f; 
    fixtureDef.restitution = 0.4f; 

    body->CreateFixture(&fixtureDef);

    isLaunched = false;
}

/**
 * @brief Updates the bird's position and rotation based on its Box2D body.
 */
void Bird::update() {
    b2Vec2 pos = body->GetPosition();
    birdShape.setPosition(pos.x, pos.y);
    birdShape.setRotation(body->GetAngle() * 180 / b2_pi);
}

/**
 * @brief Renders the bird on the provided SFML window.
 *
 * @param window The SFML window to render on.
 */
void Bird::render(sf::RenderWindow& window) {
    window.draw(birdShape);

    if (!isLaunched) {
        for (const auto& dot : trajectoryDots) {
            window.draw(dot);
        }
    }
}

/**
 * @brief Handles input events for the bird, including dragging and launching.
 *
 * @param event The SFML event to handle.
 * @param window The SFML window associated with the event.
 */
void Bird::handleInput(const sf::Event& event, const sf::RenderWindow& window) {
    if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
        sf::Vector2f mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window));
        if (birdShape.getGlobalBounds().contains(mousePos) && !isLaunched) {
            isDragging = true;
            initialClickPosition = mousePos;
        }
    }
    if (event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left && isDragging) {
        sf::Vector2f releasePosition = window.mapPixelToCoords(sf::Mouse::getPosition(window));
        sf::Vector2f launchVector = initialClickPosition - releasePosition;
        launch(b2Vec2(launchVector.x, launchVector.y));
        isDragging = false;
    }
    if (isDragging) {
        sf::Vector2f currentDragPosition = window.mapPixelToCoords(sf::Mouse::getPosition(window));
        sf::Vector2f launchVector = initialClickPosition - currentDragPosition;

        trajectoryDots = calculateTrajectory(launchVector, 10); 
    }
}

/**
 * @brief Launches the bird with a specified force.
 *
 * @param force The force vector to apply for the launch.
 */
void Bird::launch(const b2Vec2& force) {
    if (!isLaunched) {

        body->SetGravityScale(1.0f);

        b2Vec2 scaledForce = force;
        scaledForce.x *= FORCE_MULTIPLIER;
        scaledForce.y *= FORCE_MULTIPLIER;

        body->ApplyLinearImpulseToCenter(scaledForce, true);
        isLaunched = true;

        trajectoryDots.clear();
    }
}

/**
 * @brief Get the current velocity of the bird.
 * @return The velocity vector of the bird.
 */
b2Vec2 Bird::getVelocity() const {
    return body->GetLinearVelocity();
}

/**
 * @brief Check if the bird has been launched.
 * @return True if the bird has been launched, otherwise false.
 */
bool Bird::isBirdLaunched() const {
    return isLaunched;
}

/**
 * @brief Get the Box2D body of the bird.
 * @return A pointer to the Box2D body of the bird.
 */
b2Body* Bird::getBody() const {
    return body;
}

/**
 * @brief Calculate the trajectory points.
 *
 * @param launchVector The vector representing the launch direction.
 * @param numDots The number of trajectory dots to calculate.
 * @return A vector containing the calculated trajectory dots.
 */
std::vector<sf::CircleShape> Bird::calculateTrajectory(const sf::Vector2f& launchVector, int numDots) {
    std::vector<sf::CircleShape> dots;
    float timeStep = 0.1f;
    float gravityEffect = 15.0f;
    b2Vec2 startVelocity(launchVector.x, launchVector.y);

    for (int i = 0; i < numDots; ++i) {
        float time = i * timeStep;
        float x = startVelocity.x * time + birdShape.getPosition().x;
        float y = gravityEffect * 0.5f * 9.8f * time * time + startVelocity.y * time + birdShape.getPosition().y;

        sf::CircleShape dot(3);

        dot.setPosition(x, y);
        dot.setFillColor(sf::Color::White);
        dots.push_back(dot);
    }

    return dots;
}

