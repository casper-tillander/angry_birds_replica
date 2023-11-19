#include <SFML/Graphics.hpp>
#include <box2d/box2d.h>

class ImmovableObject {
private:
    sf::Sprite sprite;
    b2Body* body;

public:
    ImmovableObject(b2World* world, const sf::Texture& texture, const b2Vec2& position, const b2Vec2& size);
    void update(); // Sync Box2D physics with SFML graphics
    void render(sf::RenderWindow& window);
    // Other functionalities specific to immovable objects
};
