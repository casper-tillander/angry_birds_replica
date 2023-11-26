#ifndef SPECIALBIRD_HPP
#define SPECIALBIRD_HPP

#include "bird.hpp"

class SpecialBird : public Bird {
public:
    SpecialBird(b2World* world, const sf::Texture& texture, const b2Vec2& position);

    void handleInput(const sf::Event& event, const sf::RenderWindow& window) override;

private:
    void shootTowardsClick(const sf::Vector2f& targetPosition);
    bool isShot;

};

#endif // SPECIALBIRD_HPP
