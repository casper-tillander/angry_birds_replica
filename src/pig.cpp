#include "pig.hpp"

/**
 * @brief Constructs a Pig object.
 *
 * @param world Pointer to the Box2D world.
 * @param texture The texture for the pig.
 * @param position The initial position of the pig.
 */

Pig::Pig(b2World* world, const sf::Texture& texture, const b2Vec2& position) {
    
    pigShape.setRadius(20.0f); 
    pigShape.setTexture(&texture);
    pigShape.setOrigin(pigShape.getRadius(), pigShape.getRadius());

    b2BodyDef bodyDef;
    bodyDef.type = b2_dynamicBody;
    bodyDef.position = position;
    bodyDef.angularDamping = 1.0f; 
    bodyDef.fixedRotation = false; 
    body = world->CreateBody(&bodyDef);

    b2CircleShape circleShape;
    circleShape.m_radius = 10.0f; 

    b2FixtureDef fixtureDef;
    fixtureDef.shape = &circleShape;
    fixtureDef.density = 1.0f; 
    fixtureDef.restitution = 0.3f; 
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
    pigShape.setPosition(pos.x, pos.y);
    pigShape.setRotation(body->GetAngle() * 180 / b2_pi);
}

/**
 * @brief Renders the pig on the given window if it is alive.
 *
 * @param window The SFML render window.
 */
void Pig::render(sf::RenderWindow& window) {
    if (!isAlive) return;
    window.draw(pigShape);
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

/**
 * @brief Retrieves the pig's health.
 *
 * @return The current health of the pig.
 */
float Pig::getHealth() const {
    return health;
}

/**
 * @brief Retrieves the Box2D body associated with the pig.
 *
 * @return Pointer to the pig's Box2D body.
 */
b2Body* Pig::getBody() const {
    return body;
}