#include "wall.hpp"

/**
 * @brief Constructs a wall object.
 *
 * @param world A pointer to the Box2D world.
 * @param texture The texture to be used for the wall sprite.
 * @param position The initial position of the wall.
 */
Wall::Wall(b2World* world, const sf::Texture& texture, const b2Vec2& position) {
    
    sprite.setTexture(texture);

    sf::Vector2u textureSize = texture.getSize();
    float desiredWidth = 40.0f; ///< Desired width in pixels
    float scale = desiredWidth / textureSize.x;
    sprite.setScale(scale, scale);

    b2BodyDef bodyDef;
    bodyDef.type = b2_staticBody;
    bodyDef.position = position;
    body = world->CreateBody(&bodyDef);

    b2PolygonShape boxShape;
    boxShape.SetAsBox(20.0f, 20.0f); ///< Adjust the size of the wall

    b2FixtureDef fixtureDef;
    fixtureDef.shape = &boxShape;

    body->CreateFixture(&fixtureDef);
}

/**
 * @brief Updates the wall's position and state.
 */
void Wall::update() {
    b2Vec2 pos = body->GetPosition();
    sprite.setPosition(pos.x, pos.y);
    sprite.setRotation(body->GetAngle() * 180 / b2_pi);
}

/**
 * @brief Renders the wall on the specified window.
 *
 * @param window The rendering window to draw the wall on.
 */
void Wall::render(sf::RenderWindow& window) {
    window.draw(sprite);
}
