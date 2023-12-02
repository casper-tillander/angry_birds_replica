#include "leveleditor.hpp"

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

    highlightRectangle.setFillColor(sf::Color::Transparent);
    highlightRectangle.setOutlineColor(sf::Color::White);
    highlightRectangle.setOutlineThickness(4);
    highlightRectangle.setSize(sf::Vector2f(boxSprite.getGlobalBounds().width + 2 * 5.0f, boxSprite.getGlobalBounds().height + 2 * 5.0f));

    font.loadFromFile("../Fonts/angrybirds-regular.ttf");
    playCreatedLevelText.setFont(font);
    playCreatedLevelText.setString("Play level");
    playCreatedLevelText.setCharacterSize(30);
    playCreatedLevelText.setFillColor(sf::Color::White);


}

void LevelEditor::run() {

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

        }
    }
}