#include "wall.hpp"

Wall::Wall(b2World* world, const sf::Texture& texture, const b2Vec2& position) {
    // Initialize the sprite
    sprite.setTexture(texture);

    // Scale the sprite to the desired size
    sf::Vector2u textureSize = texture.getSize();
    float desiredWidth = 40.0f; // Desired width in pixels
    float scale = desiredWidth / textureSize.x;
    sprite.setScale(scale, scale);

    // Create a Box2D dynamic body
    b2BodyDef bodyDef;
    bodyDef.type = b2_staticBody;
    bodyDef.position = position;
    body = world->CreateBody(&bodyDef);

    // Define and attach a box-shaped fixture
    b2PolygonShape boxShape;
    boxShape.SetAsBox(20.0f, 20.0f); // Half-width and half-height in meters

    b2FixtureDef fixtureDef;
    fixtureDef.shape = &boxShape;
    fixtureDef.density = 1.0f;
    fixtureDef.restitution = 0.3f; // Adjust this value as needed

    body->CreateFixture(&fixtureDef);
}

void Wall::update() {
    b2Vec2 pos = body->GetPosition();
    sprite.setPosition(pos.x, pos.y);
    sprite.setRotation(body->GetAngle() * 180 / b2_pi);
}

void Wall::render(sf::RenderWindow& window) {
    window.draw(sprite);
}
