#include "GUI.hpp"

/**
 * @brief Constructs a GUI object and initializes the game window.
 */
GUI::GUI() : window(sf::VideoMode(1200, 700), "Angry Birds"), currentScreen(Home), currentLevel(nullptr) {
    initialize();
}

/**
 * @brief Initializes GUI components, including fonts, textures, and UI elements.
 */
void GUI::initialize() {
    // Load necessary resources
    font.loadFromFile("../Fonts/Roboto/Roboto-BlackItalic.ttf");
    birdTexture.loadFromFile("../Pictures/bird.png");
    backgroundTexture.loadFromFile("../Backgrounds/Forest Background/41524.jpg");

    // Configure title text
    titleText.setFont(font);
    titleText.setString("Angry Birds");
    titleText.setCharacterSize(90);
    titleText.setFillColor(sf::Color::White);
    titleText.setPosition(400, 100);

    // Configure play button text
    playText.setFont(font);
    playText.setString("Play");
    playText.setCharacterSize(30);
    playText.setFillColor(sf::Color::White);
    playText.setPosition(350, 300);

    // Configure background sprite
    backgroundSprite.setTexture(backgroundTexture);
    sf::Vector2u textureSize = backgroundTexture.getSize();
    sf::Vector2u windowSize = window.getSize();
    float scaleX = static_cast<float>(windowSize.x) / textureSize.x;
    float scaleY = static_cast<float>(windowSize.y) / textureSize.y;
    backgroundSprite.setScale(scaleX, scaleY);

    // Configure levels screen UI elements
    levelsText.setFont(font);
    levelsText.setString("Levels");
    levelsText.setCharacterSize(90);
    levelsText.setFillColor(sf::Color::White);
    levelsText.setPosition(450, 100);

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

    // Configure circular button shape
    ButtonShape.setRadius(30);
    ButtonShape.setScale(3, 1);
    ButtonShape.setFillColor(sf::Color(173, 216, 230));
    ButtonShape.setOutlineThickness(1);
    ButtonShape.setOutlineColor(sf::Color::White);

    sf::FloatRect playButtonBounds = ButtonShape.getLocalBounds();
    ButtonShape.setOrigin(playButtonBounds.width / 2, playButtonBounds.height / 2);
    playText.setOrigin(playText.getLocalBounds().width / 2, playText.getLocalBounds().height / 2);
    playText.setPosition(window.getSize().x / 2, 300);

    level1Text.setOrigin(level1Text.getLocalBounds().width / 2, level1Text.getLocalBounds().height / 2);
    level1Text.setPosition(window.getSize().x / 2 - 150, 400);

    level2Text.setOrigin(level2Text.getLocalBounds().width / 2, level2Text.getLocalBounds().height / 2);
    level2Text.setPosition(window.getSize().x / 2, 400);

    level3Text.setOrigin(level3Text.getLocalBounds().width / 2, level3Text.getLocalBounds().height / 2);
    level3Text.setPosition(window.getSize().x / 2 + 150, 400);
}

/**
 * @brief Runs the game loop.
 */
void GUI::run() {
    while (window.isOpen()) {
        processEvents();

        if (currentScreen == PlayingLevel) {
            currentLevel->run();
        }

        render();
    }
}

/**
 * @brief Launches a specific game level.
 *
 * @param levelNumber The number of the level to launch.
 */
void GUI::launchLevel(int levelNumber) {
    std::string levelFile = "../Levels/level" + std::to_string(levelNumber) + ".csv";
    if (currentLevel != nullptr) {
        delete currentLevel;
    }
    currentLevel = new Level(window, levelNumber, birdTexture, backgroundTexture, levelFile);
    currentScreen = PlayingLevel;
}

/**
 * @brief Processes user input events.
 */
void GUI::processEvents() {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window.close();
        }
        if (event.type == sf::Event::MouseButtonPressed) {
            if (event.mouseButton.button == sf::Mouse::Left) {
                if (currentScreen == Home && playText.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window)))) {
                    currentScreen = Levels;
                }
                if (currentScreen == Levels && level1Text.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window)))) {
                    launchLevel(1);
                }
                if (currentScreen == Levels && level2Text.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window)))) {
                    launchLevel(2);
                }
                if (currentScreen == Levels && level3Text.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window)))) {
                    launchLevel(3);
                }
            }
        }
    }
}

/**
 * @brief Updates the game state.
 */
void GUI::update() {
    // Nothing implemented that needs to be updated.
}

/**
 * @brief Renders the game's GUI components.
 */
void GUI::render() {
    window.clear();
    window.draw(backgroundSprite);
    if (currentScreen == Home) {
        drawHomeScreen();
    } else if (currentScreen == Levels) {
        drawLevelsScreen();
    }
    window.display();
}

/**
 * @brief Draws the home screen UI components.
 */
void GUI::drawHomeScreen() {
    window.draw(titleText);
    ButtonShape.setPosition(playText.getPosition());
    window.draw(ButtonShape);
    window.draw(playText);
}

/**
 * @brief Draws the levels screen UI components.
 */
void GUI::drawLevelsScreen() {
    window.draw(levelsText);

    ButtonShape.setPosition(level1Text.getPosition());
    window.draw(ButtonShape);
    window.draw(level1Text);

    ButtonShape.setPosition(level2Text.getPosition());
    window.draw(ButtonShape);
    window.draw(level2Text);

    ButtonShape.setPosition(level3Text.getPosition());
    window.draw(ButtonShape);
    window.draw(level3Text);
}



