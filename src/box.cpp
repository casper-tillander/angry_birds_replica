#include "box.hpp"

/**
 * @brief Constructs a Box object.
 *
 * @param world Pointer to the Box2D world.
 * @param texture The texture for the box.
 * @param position The initial position of the box.
 */
Box::Box(b2World* world, const sf::Texture& texture, const b2Vec2& position) {
    sprite.setTexture(texture);

    sf::Vector2u textureSize = texture.getSize();
    float desiredWidth = 40.0f; ///< Desired width in pixels
    float scale = desiredWidth / textureSize.x;
    sprite.setScale(scale, scale);

    b2BodyDef bodyDef;
    bodyDef.type = b2_dynamicBody;
    bodyDef.position = position;
    body = world->CreateBody(&bodyDef);

    b2PolygonShape boxShape;
    boxShape.SetAsBox(20.0f, 20.0f); ///< Adjust the size of the box

    b2FixtureDef fixtureDef;
    fixtureDef.shape = &boxShape;
    fixtureDef.density = 1.0f; ///< Adjust density of box
    fixtureDef.restitution = 0.3f; ///< Adjust this value for bounciness

    body->CreateFixture(&fixtureDef);
}

/**
 * @brief Updates the box's position and rotation based on its Box2D body.
 */
void Box::update() {
    b2Vec2 pos = body->GetPosition();
    sprite.setPosition(pos.x, pos.y);
    sprite.setRotation(body->GetAngle() * 180 / b2_pi);
}

/**
 * @brief Renders the box on the provided SFML window.
 *
 * @param window The SFML window to render on.
 */
void Box::render(sf::RenderWindow& window) {
    window.draw(sprite);
}
