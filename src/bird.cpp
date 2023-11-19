#include "bird.hpp"
#include <iostream>
#include <string>


Bird::Bird(b2World* world, const sf::Texture& texture, const b2Vec2& position) {
    // ... (rest of your constructor code)
    isLaunched = false;

    // Initialize the sprite
    sprite.setTexture(texture);

    // Scale the sprite to the desired size
    sf::Vector2u textureSize = texture.getSize();
    float desiredWidth = 30.0f;  // Desired width in pixels
    float scale = desiredWidth / textureSize.x;
    sprite.setScale(scale, scale);

    // Create a Box2D body
    b2BodyDef bodyDef;
    bodyDef.type = b2_dynamicBody;
    bodyDef.position = position;
    // bodyDef.gravityScale = 0.0f; // Set gravity scale to zero
    body = world->CreateBody(&bodyDef);

    // Define and attach a fixture
    b2CircleShape circleShape;
    circleShape.m_radius = 2.0f; // Adjust as needed

    b2FixtureDef fixtureDef;
    fixtureDef.shape = &circleShape;
    fixtureDef.density = 2.0f;
    fixtureDef.restitution = 0.6f; // Adjust this value for bounciness

    body->CreateFixture(&fixtureDef);

    isLaunched = false;
}

void Bird::update() {
    // Sync the sprite position and rotation with the Box2D body
    b2Vec2 pos = body->GetPosition();
    sprite.setPosition(pos.x, pos.y);
    sprite.setRotation(body->GetAngle() * 180 / b2_pi);
}

void Bird::render(sf::RenderWindow& window) {
    window.draw(sprite);
}


void Bird::handleInput(const sf::Vector2f& mousePosition, const sf::Event& event) {
    if (!isLaunched) {
        if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
            std::cout << "Mouse button pressed at (" << mousePosition.x << ", " << mousePosition.y << ")" << std::endl;
            // Check if the mouse click is inside the bird's sprite
            if (sprite.getGlobalBounds().contains(mousePosition)) {
                initialClickPosition = mousePosition;
                isBeingDragged = true;
            }
        } else if (event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left) {
            if (isBeingDragged) {
                // Calculate the launch force based on the drag distance
                sf::Vector2f dragVector = initialClickPosition - mousePosition;
                b2Vec2 launchForce(dragVector.x, dragVector.y);
                std::cout << "Launch force: (" << launchForce.x << ", " << launchForce.y << ")" << std::endl;
                launch(launchForce);
                isBeingDragged = false;
            }
        }

        if (isBeingDragged) {
            // Update the bird's Box2D body position while dragging
            body->SetTransform(b2Vec2(mousePosition.x, mousePosition.y), body->GetAngle());
        }
    }
}

void Bird::launch(const b2Vec2& force) {
    if (!isLaunched) {
        body->ApplyForceToCenter(force, true);
        body->SetGravityScale(1.0f); // Set gravity scale to 1.0f when launched
        isLaunched = true;
    }
}

