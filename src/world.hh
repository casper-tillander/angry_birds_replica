// world.hh
#ifndef WORLD_HH
#define WORLD_HH

#include <Box2D/Box2D.h>
#include <SFML/Graphics.hpp>
#include <vector>
#include <string>

enum class GameObjectType {
    Bird,
    Enemy,
    Obstacle
};

class GameObject {
public:
    GameObjectType type;
    virtual void Update() = 0;
    virtual void Render(sf::RenderWindow& window) = 0;
};

class Game {
private:
    std::vector<GameObject*> objects;
    b2World* world;
    sf::RenderWindow window;

public:
    Game();
    ~Game();
    void Run();
    void LoadMap(const std::string& path);
};

#endif // WORLD_HH

