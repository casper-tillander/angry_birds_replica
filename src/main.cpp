#include <SFML/Graphics.hpp>
#include <box2d/box2d.h>

int main() {
    // Window setup
    sf::RenderWindow window(sf::VideoMode(800, 600), "Ball Bouncing Simulation");

    // Box2D world setup with gravity
    b2Vec2 gravity(0.0f, 9.8f); // Earth gravity
    b2World world(gravity);

    // Create the ground
    b2BodyDef groundBodyDef;
    groundBodyDef.position.Set(400.0f, 550.0f); // Position at the bottom of the window
    b2Body* groundBody = world.CreateBody(&groundBodyDef);
    b2PolygonShape groundBox;
    groundBox.SetAsBox(400.0f, 10.0f); // Large enough to cover the window's width
    groundBody->CreateFixture(&groundBox, 0.0f);

    // Create the ball
    b2BodyDef ballBodyDef;
    ballBodyDef.type = b2_dynamicBody;
    ballBodyDef.position.Set(400.0f, 50.0f); // Drop from the top of the window
    b2Body* ballBody = world.CreateBody(&ballBodyDef);
    b2CircleShape ballCircle;
    ballCircle.m_radius = 30.0f; // Radius of the ball
    b2FixtureDef ballFixtureDef;
    ballFixtureDef.shape = &ballCircle;
    ballFixtureDef.density = 1.0f;
    ballFixtureDef.restitution = 0.6f; // Bounciness
    ballBody->CreateFixture(&ballFixtureDef);

    // Main game loop
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        // Update the Box2D world
        world.Step(1.0f / 60.0f, 6, 2);

        // Clear the window
        window.clear();

        // Draw the ground
        sf::RectangleShape ground(sf::Vector2f(800.0f, 20.0f));
        ground.setPosition(0.0f, 550.0f);
        ground.setFillColor(sf::Color::Green);
        window.draw(ground);

        // Draw the ball
        sf::CircleShape ball(30.0f);
        ball.setFillColor(sf::Color::Red);
        ball.setPosition(ballBody->GetPosition().x - 30.0f, ballBody->GetPosition().y - 30.0f);
        window.draw(ball);

        // Display everything
        window.display();
    }

    return 0;
}

