#include "wall.hpp"

/**
 * @brief Constructs a wall object.
 *
 * @param world A pointer to the Box2D world.
 * @param texture The texture to be used for the wall sprite.
 * @param position The initial position of the wall.
 */
Wall::Wall(b2World* world, const sf::Texture& texture, const b2Vec2& position) {
    
    wallShape.setSize(sf::Vector2f(40.0f, 40.0f)); ///< Adjust the size of the wall
    wallShape.setTexture(&texture);
    wallShape.setOrigin(wallShape.getSize().x / 2, wallShape.getSize().y / 2);

    b2BodyDef bodyDef;
    bodyDef.type = b2_staticBody;
    bodyDef.position = position;
    body = world->CreateBody(&bodyDef);

    b2PolygonShape boxShape;
    boxShape.SetAsBox(20.0f, 20.0f); ///< About 2 times smaller than wallShape

    b2FixtureDef fixtureDef;
    fixtureDef.shape = &boxShape;

    body->CreateFixture(&fixtureDef);
}

/**
 * @brief Updates the wall's position and state.
 */
void Wall::update() {
    b2Vec2 pos = body->GetPosition();
    wallShape.setPosition(pos.x, pos.y);
    wallShape.setRotation(body->GetAngle() * 180 / b2_pi);
}

/**
 * @brief Renders the wall on the specified window.
 *
 * @param window The rendering window to draw the wall on.
 */
void Wall::render(sf::RenderWindow& window) {
    window.draw(wallShape);
}

/**
 * @brief Gets the Box2D body associated with the wall.
 *
 * @return A pointer to the Box2D body.
 */
b2Body* Wall::getBody() const {
    return body;
}

/**
 * @brief Gets the position of the wall.
 *
 * @return The position of the wall in the Box2D world.
 */
b2Vec2 Wall::getPosition() const {
    return body->GetPosition();
}