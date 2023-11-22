#include "pig.hpp"

Pig::Pig(b2World* world, const sf::Texture& texture, const b2Vec2& position) {
    
    sprite.setTexture(texture);

    sf::Vector2u textureSize = texture.getSize();
    float desiredWidth = 40.0f; ///< Desired width in pixels
    float scale = desiredWidth / textureSize.x;
    sprite.setScale(scale, scale);

    b2BodyDef bodyDef;
    bodyDef.type = b2_dynamicBody;
    bodyDef.position = position;
    body = world->CreateBody(&bodyDef);

    b2CircleShape circleShape;
    circleShape.m_radius = 20.0f; ///< Adjust the size of the pig

    b2FixtureDef fixtureDef;
    fixtureDef.shape = &circleShape;
    fixtureDef.density = 1.0f; ///< Adjust density of pig
    fixtureDef.restitution = 0.3f; ///< Adjust this value for bounciness

    body->CreateFixture(&fixtureDef);

    body->GetUserData().pointer = reinterpret_cast<uintptr_t>(this);

    markedForDeletion = false;
    isAlive = true;
    health = 100.0f;
}

/**
 * @brief Updates the pig's position and rotation if it is alive.
 */
void Pig::update() {
    if (!isAlive) return;

    b2Vec2 pos = body->GetPosition();
    sprite.setPosition(pos.x, pos.y);
    sprite.setRotation(body->GetAngle() * 180 / b2_pi);
}

/**
 * @brief Renders the pig on the given window if it is alive.
 *
 * @param window The SFML render window.
 */
void Pig::render(sf::RenderWindow& window) {
    if (!isAlive) return;
    window.draw(sprite);
}

/**
 * @brief Applies damage to the pig's health and marks it for deletion if health reaches zero or below.
 *
 * @param damage Amount of damage to apply.
 */
void Pig::takeDamage(float damage) {
    health -= damage;
    if (health <= 0) {
        isAlive = false;
        markForDeletion();
    }
}

/**
 * @brief Marks the pig for deletion.
 */
void Pig::markForDeletion() {
    markedForDeletion = true;
}

/**
 * @brief Checks if the pig is marked for deletion.
 *
 * @return true if marked for deletion, false otherwise.
 */
bool Pig::isMarkedForDeletion() const {
    return markedForDeletion;
}

/**
 * @brief Checks if the pig is alive.
 *
 * @return true if the pig is alive, false otherwise.
 */
bool Pig::alive() const {
    return isAlive;
}

/**
 * @brief Destroys the Box2D body associated with the pig if it exists and the world is not locked.
 */
void Pig::destroyBody() {
    if (body && !body->GetWorld()->IsLocked()) {
        body->GetWorld()->DestroyBody(body);
        body = nullptr;
    }
}
