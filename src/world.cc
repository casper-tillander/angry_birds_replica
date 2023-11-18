// world.cc
#include "world.hh"
#include <iostream>

Game::Game() : window(sf::VideoMode(800, 600), "Angry Birds Game"), world(new b2World(b2Vec2(0.0f, -10.0f))) {
    // Load the map, initialize other game elements
}

Game::~Game() {
    for (auto obj : objects) {
        delete obj;
    }
    delete world;
}

void Game::Run() {
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Update physics
        world->Step(1.0f / 60.0f, 6, 2);

        // Update all game objects
        for (auto obj : objects) {
            obj->Update();
        }

        // Render game state
        window.clear();
        for (auto obj : objects) {
            obj->Render(window);
        }
        window.display();
    }
}

void Game::LoadMap(const std::string& path) {
    // Implement map loading logic
}

// Main function for testing
int main() {
    Game game;
    game.Run();
    return 0;
}
