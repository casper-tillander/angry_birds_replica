#include <SFML/Graphics.hpp>
#include <box2d/box2d.h>

class Pig {
private:
    sf::Sprite sprite;
    b2Body* body;

public:
    Pig(b2World* world, const sf::Texture& texture, const b2Vec2& position);
    void update(); // Sync Box2D physics with SFML graphics
    void render(sf::RenderWindow& window);
    // Additional functionalities, e.g., scoring when hit
};