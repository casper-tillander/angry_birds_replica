#include "bird.hpp"

/**
 * @brief Constructs a Bird object.
 *
 * @param world Pointer to the Box2D world.
 * @param texture The texture for the bird.
 * @param position The initial position of the bird.
 */
Bird::Bird(b2World* world, const sf::Texture& texture, const b2Vec2& position) {
    isLaunched = false;

    sprite.setTexture(texture);

    sf::Vector2u textureSize = texture.getSize();
    float desiredWidth = 50.0f; ///< Desired width in pixels
    float scale = desiredWidth / textureSize.x;
    sprite.setScale(scale, scale);

    b2BodyDef bodyDef;
    bodyDef.type = b2_dynamicBody;
    bodyDef.position = position;
    bodyDef.gravityScale = 0.0f;
    // bodyDef.angularDamping = 3.0f; ///< Makes the bird stop spinning after some time
    bodyDef.fixedRotation = true; ///< Set to 'true' if the bird shouldn't spin
    body = world->CreateBody(&bodyDef);

    b2CircleShape circleShape;
    circleShape.m_radius = 20.0f; ///< Adjust the size of the bird

    b2FixtureDef fixtureDef;
    fixtureDef.shape = &circleShape;
    fixtureDef.density = 1.0f; ///< Adjust density of bird
    fixtureDef.restitution = 0.4f; ///< Adjust this value for bounciness

    body->CreateFixture(&fixtureDef);

    isLaunched = false;
}

/**
 * @brief Updates the bird's position and rotation based on its Box2D body.
 */
void Bird::update() {
    b2Vec2 pos = body->GetPosition();
    b2Vec2 vel = body->GetLinearVelocity();

    sprite.setPosition(pos.x, pos.y);
    sprite.setRotation(body->GetAngle() * 180 / b2_pi);
}

/**
 * @brief Renders the bird on the provided SFML window.
 *
 * @param window The SFML window to render on.
 */
void Bird::render(sf::RenderWindow& window) {
    window.draw(sprite);
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
        if (sprite.getGlobalBounds().contains(mousePos) && !isLaunched) {
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
    }
}




