#include "bird.hpp"

Bird::Bird(b2World* world, const sf::Texture& texture, const b2Vec2& position) {
    // ... (rest of your constructor code)
    isLaunched = false;

    // Initialize the sprite
    sprite.setTexture(texture);

    // Scale the sprite to the desired size
    sf::Vector2u textureSize = texture.getSize();
    float desiredWidth = 50.0f;  // Desired width in pixels
    float scale = desiredWidth / textureSize.x;
    sprite.setScale(scale, scale);

    // Create a Box2D body
    b2BodyDef bodyDef;
    bodyDef.type = b2_dynamicBody;
    bodyDef.position = position;
    bodyDef.gravityScale = 0.0f; // Set gravity scale to zero
    body = world->CreateBody(&bodyDef);

    // Define and attach a fixture
    b2CircleShape circleShape;
    circleShape.m_radius = 20.0f; // Adjust as needed

    b2FixtureDef fixtureDef;
    fixtureDef.shape = &circleShape;
    fixtureDef.density = 1.0f;
    fixtureDef.restitution = 0.4f; // Adjust this value for bounciness

    body->CreateFixture(&fixtureDef);

    isLaunched = false;
}

void Bird::update() {
    b2Vec2 pos = body->GetPosition();
    b2Vec2 vel = body->GetLinearVelocity();

    // Sync the sprite position and rotation with the Box2D body
    sprite.setPosition(pos.x, pos.y);
    sprite.setRotation(body->GetAngle() * 180 / b2_pi);
}

void Bird::render(sf::RenderWindow& window) {
    window.draw(sprite);
}


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


void Bird::launch(const b2Vec2& force) {
    if (!isLaunched) {
        // Reset gravity scale to be affected by gravity
        body->SetGravityScale(1.0f);

        // Apply exaggerated force
        b2Vec2 scaledForce = force;
        scaledForce.x *= FORCE_MULTIPLIER;
        scaledForce.y *= FORCE_MULTIPLIER;

        // body->ApplyForceToCenter(scaledForce, true);
        body->ApplyLinearImpulseToCenter(scaledForce, true); // Use this for an immediate impulse
        isLaunched = true;
    }
}



