#include "box.hpp"

/**
 * @brief Constructs a Box object.
 *
 * @param world Pointer to the Box2D world.
 * @param texture The texture for the box.
 * @param position The initial position of the box.
 */
Box::Box(b2World* world, const sf::Texture& texture, const b2Vec2& position) {

    boxShape.setSize(sf::Vector2f(40.0f, 40.0f)); ///< Adjust the size of the box
    boxShape.setTexture(&texture);
    boxShape.setOrigin(boxShape.getSize().x / 2, boxShape.getSize().y / 2);

    b2BodyDef bodyDef;
    bodyDef.type = b2_dynamicBody;
    bodyDef.position = position;
    body = world->CreateBody(&bodyDef);

    b2PolygonShape boxShape;
    boxShape.SetAsBox(20.0f, 20.0f); ///< About 2 times smaller than boxShape

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
    boxShape.setPosition(pos.x, pos.y);
    boxShape.setRotation(body->GetAngle() * 180 / b2_pi);
}

/**
 * @brief Renders the box on the provided SFML window.
 *
 * @param window The SFML window to render on.
 */
void Box::render(sf::RenderWindow& window) {
    window.draw(boxShape);
}
