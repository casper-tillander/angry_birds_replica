#ifndef LEVEL_EDITOR_HPP
#define LEVEL_EDITOR_HPP

#include <SFML/Graphics.hpp>
#include <box2d/box2d.h>

/**
 * @class LevelEditor
 * @brief Represents a tool to create game levels and edit them visually.
 */

class LevelEditor {
private:
// Member variables
    int levelNumber;
    int chosenObject = 1;

    sf::Text playCreatedLevelText;
    sf::Font font;
    sf::CircleShape ButtonShape;

    sf::RenderWindow& window;
    sf::Texture backgroundTexture;
    sf::Sprite backgroundSprite;

    sf::Texture pigTexture;
    sf::Texture wallTexture;
    sf::Texture boxTexture;

    sf::Sprite pigSprite;
    sf::Sprite wallSprite;
    sf::Sprite boxSprite;

    sf::CircleShape pigShape;
    sf::RectangleShape boxShape;
    sf::RectangleShape wallShape;

    std::vector<sf::Vector2f> pigPositions;
    std::vector<sf::Vector2f> boxPositions;
    std::vector<sf::Vector2f> wallPositions;

    sf::RectangleShape highlightRectangle;

    std::string filePath = "../Createdlevels/createdlevel.csv";

public:
    /**
     * @brief Constructs a Level Editor object.
     * 
     * @param win Reference to the game's window.
     * @param number The background number for the level.
     * @param backTex The texture for the background.
     */
    LevelEditor(sf::RenderWindow& win, int number, const sf::Texture& backTex);

    /**
     * @brief Runs the events of the Level Editor.
     */
    std::string run();

    /**
     * @brief Sets up the Level Editor with objects.
     */
    void setUpLevel();

    /**
     * @brief Adds objects to CSV file.
     * @param chosenObject The object added to the game.
     * @param mousePos The position of the added object.
     * @param filePath The path to the CSV file to add to.
     */
    void addObject(int chosenObject, sf::Vector2f mousePos, std::string& filePath);

    /**
     * @brief Draws the objects on the screen.
     */
    void drawObject();

};


#endif // LEVEL_EDITOR_HPP