#include "GUI.hpp"

GUI::GUI() : window(sf::VideoMode(1200, 700), "Angry Birds"), currentScreen(Home), currentLevel(nullptr) {
    initialize();
}

void GUI::initialize() {
    // Load a font, texture for bird
    font.loadFromFile("../Fonts/Roboto/Roboto-BlackItalic.ttf");
    birdTexture.loadFromFile("../Pictures/bird.png");

    // Setup title text
    titleText.setFont(font);
    titleText.setString("Angry Birds");
    titleText.setCharacterSize(90);
    titleText.setFillColor(sf::Color::White);
    titleText.setPosition(400, 100);

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
    levelsText.setCharacterSize(90);
    levelsText.setFillColor(sf::Color::White);
    levelsText.setPosition(450, 100);

    // Setup level buttons
    level1Text.setFont(font);
    level1Text.setString("Level 1");
    level1Text.setCharacterSize(30);
    level1Text.setFillColor(sf::Color::White);
    level1Text.setPosition(100, 300);

    level2Text.setFont(font);
    level2Text.setString("Level 2");
    level2Text.setCharacterSize(30);
    level2Text.setFillColor(sf::Color::White);
    level2Text.setPosition(350, 300);

    level3Text.setFont(font);
    level3Text.setString("Level 3");
    level3Text.setCharacterSize(30);
    level3Text.setFillColor(sf::Color::White);
    level3Text.setPosition(600, 300);

    // Setup button shape (oval)
    ButtonShape.setRadius(30); // This will be the height of the oval
    ButtonShape.setScale(3, 1); // This will make the width 3 times the height
    ButtonShape.setFillColor(sf::Color(173, 216, 230)); // Light blue color
    ButtonShape.setOutlineThickness(1);
    ButtonShape.setOutlineColor(sf::Color::White);

    // Center the playText on the ButtonShape
    sf::FloatRect playButtonBounds = ButtonShape.getLocalBounds();
    ButtonShape.setOrigin(playButtonBounds.width / 2, playButtonBounds.height / 2);
    playText.setOrigin(playText.getLocalBounds().width / 2, playText.getLocalBounds().height / 2);
    playText.setPosition(window.getSize().x / 2, 300);

    // Center the level1Text on the ButtonShape
    level1Text.setOrigin(level1Text.getLocalBounds().width / 2, level1Text.getLocalBounds().height / 2);
    level1Text.setPosition(window.getSize().x / 2 - 150, 400);

    // Center the level2Text on the ButtonShape
    level2Text.setOrigin(level2Text.getLocalBounds().width / 2, level2Text.getLocalBounds().height / 2);
    level2Text.setPosition(window.getSize().x / 2, 400);

    // Center the level3Text on the ButtonShape
    level3Text.setOrigin(level3Text.getLocalBounds().width / 2, level3Text.getLocalBounds().height / 2);
    level3Text.setPosition(window.getSize().x / 2 + 150, 400);
    }

void GUI::run() {
    while (window.isOpen()) {
        processEvents();

        if (currentScreen == PlayingLevel) {
            currentLevel->run();  // Run the level logic
        }

        render();
    }
}

void GUI::launchLevel(int levelNumber) {
    if (currentLevel != nullptr) {
        delete currentLevel;
    }
    currentLevel = new Level(window, levelNumber, birdTexture, backgroundTexture);
    currentScreen = PlayingLevel;
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
                // Handling for level buttons
                if (currentScreen == Levels && level1Text.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window)))) {
                    launchLevel(1); // Launch Level 1
                }
                if (currentScreen == Levels && level2Text.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window)))) {
                launchLevel(2); // Launch Level 2
                }
                if (currentScreen == Levels && level3Text.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window)))) {
                    launchLevel(3); // Launch Level 3
                }
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
    ButtonShape.setPosition(playText.getPosition()); // No need for offset, origins are centered
    window.draw(ButtonShape); // Draw the button shape first
    window.draw(playText); // Draw the text over the button
}

void GUI::drawLevelsScreen() {
    window.draw(levelsText);

    // Position and draw the button for Level 1
    ButtonShape.setPosition(level1Text.getPosition()); // Origins are centered
    window.draw(ButtonShape); // Draw the button shape first
    window.draw(level1Text); // Draw the text over the button

    ButtonShape.setPosition(level2Text.getPosition()); // Origins are centered
    window.draw(ButtonShape); // Draw the button shape first
    window.draw(level2Text); // Draw the text over the button

    ButtonShape.setPosition(level3Text.getPosition()); // Origins are centered
    window.draw(ButtonShape); // Draw the button shape first
    window.draw(level3Text); // Draw the text over the button

}


