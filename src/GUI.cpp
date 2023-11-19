#include "GUI.hpp"

GUI::GUI() : window(sf::VideoMode(800, 600), "Angry Birds"), currentScreen(Home) {
    initialize();
}

void GUI::initialize() {
    // Load a font
    font.loadFromFile("../Fonts/Roboto/Roboto-Black.ttf");

    // Setup title text
    titleText.setFont(font);
    titleText.setString("Angry Birds");
    titleText.setCharacterSize(70);
    titleText.setFillColor(sf::Color::White);
    titleText.setPosition(250, 100);

    // Setup play text
    playText.setFont(font);
    playText.setString("Play");
    playText.setCharacterSize(30);
    playText.setFillColor(sf::Color::White);
    playText.setPosition(350, 300);

    // Load background texture and set it to the sprite
    backgroundTexture.loadFromFile("../Backgrounds/Forest Background/41524.jpg");
    backgroundSprite.setTexture(backgroundTexture);

    // Scale the sprite to fit the window size
    sf::Vector2u textureSize = backgroundTexture.getSize();
    sf::Vector2u windowSize = window.getSize();
    
    // Calculate the scale factors
    float scaleX = static_cast<float>(windowSize.x) / textureSize.x;
    float scaleY = static_cast<float>(windowSize.y) / textureSize.y;

    // Set the scale to the sprite
    backgroundSprite.setScale(scaleX, scaleY);

    // Setup levels screen text objects
    levelsText.setFont(font);
    levelsText.setString("Levels");
    levelsText.setCharacterSize(70);
    levelsText.setFillColor(sf::Color::White);
    levelsText.setPosition(300, 100);

    // Setup level buttons
    level1Text.setFont(font);
    level1Text.setString("Level 1");
    level1Text.setCharacterSize(30);
    level1Text.setFillColor(sf::Color::White);
    level1Text.setPosition(200, 300);

    level2Text.setFont(font);
    level2Text.setString("Level 2");
    level2Text.setCharacterSize(30);
    level2Text.setFillColor(sf::Color::White);
    level2Text.setPosition(350, 300);

    level3Text.setFont(font);
    level3Text.setString("Level 3");
    level3Text.setCharacterSize(30);
    level3Text.setFillColor(sf::Color::White);
    level3Text.setPosition(500, 300);

    ButtonShape.setRadius(30); // Set the radius
    ButtonShape.setScale(3, 1); // Scale to make it oval (2 times wider than its height)
    ButtonShape.setFillColor(sf::Color(173, 216, 230)); // Fill color
    ButtonShape.setOutlineThickness(1); //  Outline thickness
    ButtonShape.setOutlineColor(sf::Color::White); // Outline color
}

void GUI::run() {
    while (window.isOpen()) {
        processEvents();
        update();
        render();
    }
}

void GUI::processEvents() {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window.close();
        }
        if (event.type == sf::Event::MouseButtonPressed) {
            if (event.mouseButton.button == sf::Mouse::Left) {
                if (currentScreen == Home && playText.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window)))) {
                    currentScreen = Levels; // Change the screen state to Levels
                }
                // TODO: Handling for level buttons
            }
        }
    }
}

void GUI::update() {
    // Currently empty, but you can add any update logic here later if needed
}

void GUI::render() {
    window.clear();
    window.draw(backgroundSprite); // Draw the background first
    if (currentScreen == Home) {
        drawHomeScreen();
    } else if (currentScreen == Levels) {
        drawLevelsScreen();
    }
    window.display();
}

void GUI::drawHomeScreen() {
    window.draw(titleText);
    ButtonShape.setPosition(playText.getPosition() - sf::Vector2f(10, 10)); // Set the button's position
    window.draw(ButtonShape); // Draw the button shape
    window.draw(playText); // Draw the text over the button
}


void GUI::drawLevelsScreen() {
    window.draw(levelsText);

    // Draw button for Level 1
    ButtonShape.setPosition(level1Text.getPosition() - sf::Vector2f(10, 10)); // Adjust position for Level 1
    window.draw(ButtonShape);
    window.draw(level1Text);

    // Draw button for Level 2
    ButtonShape.setPosition(level2Text.getPosition() - sf::Vector2f(10, 10)); // Adjust position for Level 2
    window.draw(ButtonShape);
    window.draw(level2Text);

    // Draw button for Level 3
    ButtonShape.setPosition(level3Text.getPosition() - sf::Vector2f(10, 10)); // Adjust position for Level 3
    window.draw(ButtonShape);
    window.draw(level3Text);
}



