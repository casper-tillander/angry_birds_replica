#include "leveleditor.hpp"
#include <fstream>
#include <sstream>
#include <iostream>

/**
 * @brief Constructs a Level Editor object.
 * 
 * @param win Reference to the game's window.
 * @param number The background number for the level.
 * @param backTex The texture for the background.
 */
LevelEditor::LevelEditor(sf::RenderWindow& win, int number, const sf::Texture& backTex) 
    : levelNumber(number), window(win) {

    backgroundTexture = backTex;
    backgroundSprite.setTexture(backgroundTexture);
    sf::Vector2u textureSize = backgroundTexture.getSize();
    sf::Vector2u windowSize = window.getSize();
    float scaleX = static_cast<float>(windowSize.x) / textureSize.x;
    float scaleY = static_cast<float>(windowSize.y) / textureSize.y;
    backgroundSprite.setScale(scaleX, scaleY);
    
    pigTexture.loadFromFile("../Pictures/pig.png");
    boxTexture.loadFromFile("../Pictures/box.jpg");
    wallTexture.loadFromFile("../Pictures/wall.jpg");

    pigSprite.setTexture(pigTexture);
    boxSprite.setTexture(boxTexture);
    wallSprite.setTexture(wallTexture);

    pigSprite.setScale(0.1f, 0.1f);
    boxSprite.setScale(0.2f, 0.2f);
    wallSprite.setScale(0.1f, 0.1f);

    pigShape.setRadius(25.0f); 
    pigShape.setTexture(&pigTexture);
    pigShape.setOrigin(pigShape.getRadius(), pigShape.getRadius());

    boxShape.setSize(sf::Vector2f(40.0f, 40.0f)); 
    boxShape.setTexture(&boxTexture);
    boxShape.setOrigin(boxShape.getSize().x / 2, boxShape.getSize().y / 2);

    wallShape.setSize(sf::Vector2f(40.0f, 40.0f)); 
    wallShape.setTexture(&wallTexture);
    wallShape.setOrigin(wallShape.getSize().x / 2, wallShape.getSize().y / 2);

    highlightRectangle.setFillColor(sf::Color::Transparent);
    highlightRectangle.setOutlineColor(sf::Color::White);
    highlightRectangle.setOutlineThickness(4);
    highlightRectangle.setSize(sf::Vector2f(boxSprite.getGlobalBounds().width + 2 * 5.0f, boxSprite.getGlobalBounds().height + 2 * 5.0f));

    font.loadFromFile("../Fonts/FEASFBRG.TTF");;
    playCreatedLevelText.setFont(font);
    playCreatedLevelText.setString("Play level");
    playCreatedLevelText.setCharacterSize(30);
    playCreatedLevelText.setFillColor(sf::Color::White);

    std::ofstream file(filePath, std::ios::trunc);
    if (file.is_open()) {
        file << "type,x,y" << std::endl;
    }
}

/**
 * @brief Runs the events of the Level Editor.
 */
std::string LevelEditor::run() {

    while (window.isOpen()) {
        window.display();

        sf::Event event;
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed) {
                    window.close();
                }

                if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
                    sf::Vector2f mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window));
                    if (pigSprite.getGlobalBounds().contains(mousePos)) {
                        chosenObject = 1;
                    } else if (boxSprite.getGlobalBounds().contains(mousePos)) {
                        chosenObject = 2;
                    } else if (wallSprite.getGlobalBounds().contains(mousePos)) {
                        chosenObject = 3;
                    } else if (playCreatedLevelText.getGlobalBounds().contains(mousePos)) {
                        return filePath;
                    } else {
                        addObject(chosenObject, mousePos, filePath);
                    }
                }

                if (event.type == sf::Event::MouseMoved) {
                    sf::Vector2f mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window));
                    if (playCreatedLevelText.getGlobalBounds().contains(mousePos)) {
                        playCreatedLevelText.setCharacterSize(35);
                    } else {
                        playCreatedLevelText.setCharacterSize(30);
                    }
                }
            }

            setUpLevel();
            drawObject();
    }
}

/**
 * @brief Sets up the Level Editor with objects.
 */
void LevelEditor::setUpLevel() {
    window.draw(backgroundSprite);


    pigSprite.setPosition(100, 645);
    window.draw(pigSprite);

    boxSprite.setPosition(200, 645);
    window.draw(boxSprite);

    wallSprite.setPosition(300, 645);
    window.draw(wallSprite);

    if (chosenObject == 1) {
        highlightRectangle.setPosition(pigSprite.getPosition() - sf::Vector2f(5.0f, 5.0f));
    } else if (chosenObject == 2) {
        highlightRectangle.setPosition(boxSprite.getPosition() - sf::Vector2f(5.0f, 5.0f));
    } else if (chosenObject == 3) {
        highlightRectangle.setPosition(wallSprite.getPosition() - sf::Vector2f(5.0f, 5.0f));
    }
    window.draw(highlightRectangle);

    playCreatedLevelText.setOrigin(playCreatedLevelText.getLocalBounds().width / 2, playCreatedLevelText.getLocalBounds().height / 1.3);
    ButtonShape.setRadius(30);
    ButtonShape.setScale(3, 1);
    ButtonShape.setFillColor(sf::Color(173, 216, 230));
    ButtonShape.setOutlineThickness(1);
    ButtonShape.setOutlineColor(sf::Color::White);
    ButtonShape.setOrigin(ButtonShape.getLocalBounds().width / 2, ButtonShape.getLocalBounds().height / 2);

    ButtonShape.setPosition(1105, 50);
    window.draw(ButtonShape);
    playCreatedLevelText.setPosition(ButtonShape.getPosition());
    window.draw(playCreatedLevelText);

    playCreatedLevelText.setOrigin(playCreatedLevelText.getLocalBounds().width / 2, playCreatedLevelText.getLocalBounds().height / 1.3);
    ButtonShape.setRadius(30);
    ButtonShape.setScale(3, 1);
    ButtonShape.setFillColor(sf::Color(173, 216, 230));
    ButtonShape.setOutlineThickness(1);
    ButtonShape.setOutlineColor(sf::Color::White);
    ButtonShape.setOrigin(ButtonShape.getLocalBounds().width / 2, ButtonShape.getLocalBounds().height / 2);

    ButtonShape.setPosition(1105, 50);
    window.draw(ButtonShape);
    playCreatedLevelText.setPosition(ButtonShape.getPosition());
    window.draw(playCreatedLevelText);

}

/**
 * @brief Adds objects to CSV file.
 * @param chosenObject The object added to the game.
 * @param mousePos The position of the added object.
 * @param filePath The path to the CSV file to add to.
 */
void LevelEditor::addObject(int chosenObject, sf::Vector2f mousePos, std::string& filePath) {
    std::ofstream file(filePath, std::ios::app);
    if (file.is_open()) {
        if (chosenObject == 1) {
            file << "pig," << mousePos.x << "," << mousePos.y << std::endl;
            pigPositions.push_back(mousePos);
        } else if (chosenObject == 2) {
            file << "box," << mousePos.x << "," << mousePos.y << std::endl;
            boxPositions.push_back(mousePos);
        } else if (chosenObject == 3) {
            file << "wall," << mousePos.x << "," << mousePos.y << std::endl;
            wallPositions.push_back(mousePos);
        }
        file.close();
    }
    else {
        std::cerr << "Failed to open file" << std::endl;
    }

}

/**
 * @brief Draws the objects on the screen.
 */
void LevelEditor::drawObject() {
    for (const auto& pigPos : pigPositions) {
        pigShape.setPosition(pigPos);
        window.draw(pigShape);
    }
    for (const auto& boxPos : boxPositions) {
        boxShape.setPosition(boxPos);
        window.draw(boxShape);
    }
    for (const auto& wallPos : wallPositions) {
        wallShape.setPosition(wallPos);
        window.draw(wallShape);
    }
}
    