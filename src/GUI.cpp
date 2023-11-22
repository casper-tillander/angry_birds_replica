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
    font.loadFromFile("../Fonts/angrybirds-regular.ttf");
    birdTexture.loadFromFile("../Pictures/bird.png");
    backgroundTexture.loadFromFile("../Backgrounds/homescreen.png");
    levelBackgroundTexture.loadFromFile("../Backgrounds/levels.png");

    // Configure title text
    /*
    titleText.setFont(font);
    titleText.setString("Angry Birds");
    titleText.setCharacterSize(130);
    titleText.setFillColor(sf::Color::White);
    titleText.setPosition(270, 100);
    */

    // Configure play button text
    playText.setFont(font);
    playText.setString("Play");
    playText.setCharacterSize(30);
    playText.setFillColor(sf::Color::White);
    // Center text on button shape
    playText.setOrigin(playText.getLocalBounds().width / 2, playText.getLocalBounds().height / 1.3);

    // Configure background sprite
    backgroundSprite.setTexture(backgroundTexture);
    sf::Vector2u textureSize = backgroundTexture.getSize();
    sf::Vector2u windowSize = window.getSize();
    float scaleX = static_cast<float>(windowSize.x) / textureSize.x;
    float scaleY = static_cast<float>(windowSize.y) / textureSize.y;
    backgroundSprite.setScale(scaleX, scaleY);

    // Configure levels screen UI elements
    /*
    levelsText.setFont(font);
    levelsText.setString("Levels");
    levelsText.setCharacterSize(130);
    levelsText.setFillColor(sf::Color::White);
    levelsText.setPosition(450, 100);
    */

    level1Text.setFont(font);
    level1Text.setString("Level 1");
    level1Text.setCharacterSize(30);
    level1Text.setFillColor(sf::Color::White);
    level1Text.setOrigin(level1Text.getLocalBounds().width / 2, level1Text.getLocalBounds().height / 1.3);

    level2Text.setFont(font);
    level2Text.setString("Level 2");
    level2Text.setCharacterSize(30);
    level2Text.setFillColor(sf::Color::White);
    level2Text.setOrigin(level2Text.getLocalBounds().width / 2, level2Text.getLocalBounds().height / 1.3);

    level3Text.setFont(font);
    level3Text.setString("Level 3");
    level3Text.setCharacterSize(30);
    level3Text.setFillColor(sf::Color::White);
    level3Text.setOrigin(level3Text.getLocalBounds().width / 2, level3Text.getLocalBounds().height / 1.3);

    // Configure circular button shape
    ButtonShape.setRadius(30);
    ButtonShape.setScale(3, 1);
    ButtonShape.setFillColor(sf::Color(173, 216, 230));
    ButtonShape.setOutlineThickness(1);
    ButtonShape.setOutlineColor(sf::Color::White);
    ButtonShape.setOrigin(ButtonShape.getLocalBounds().width / 2, ButtonShape.getLocalBounds().height / 2);
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
    std::string backgroundFile = "../Backgrounds/background" + std::to_string(levelNumber) + ".jpg";

    backgroundTexture.loadFromFile(backgroundFile);

    backgroundSprite.setTexture(backgroundTexture);

    std::string levelFile = "../Levels/level" + std::to_string(levelNumber) + ".csv";
    if (currentLevel != nullptr) {
        delete currentLevel;
    }
    currentLevel = new Level(window, levelNumber, backgroundTexture, levelFile);
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
                if (currentScreen == Home) {
                    // Check if the mouse is over the "Play" button
                    if (playText.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window)))) {
                        currentScreen = Levels;
                    }
                }
                if (currentScreen == Levels) {
                    // Check if the mouse is over a level button
                    if (level1Text.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window)))) {
                        launchLevel(1);
                    }
                    if (level2Text.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window)))) {
                        launchLevel(2);
                    }
                    if (level3Text.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window)))) {
                        launchLevel(3);
                    }
                }
            }
        }
        if (event.type == sf::Event::MouseMoved) {
            if (currentScreen == Home) {
                // Checks if the mouse is over the "Play" button and applys a hover effect
                if (playText.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window)))) {
                    playText.setCharacterSize(35);
                    ButtonShape.setFillColor(sf::Color(143, 188, 219));
                } else {
                    playText.setCharacterSize(30);
                    ButtonShape.setFillColor(sf::Color(173, 216, 230));
                }
            }
            if (currentScreen == Levels) {
                // Checks if the mouse is over a level button and applys a hover effect
                if (level1Text.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window)))) {
                    level1Text.setCharacterSize(35);
                    ButtonShape.setFillColor(sf::Color(143, 188, 219));
                } else {
                    level1Text.setCharacterSize(30);
                }
                if (level2Text.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window)))) {
                    level2Text.setCharacterSize(35);
                    ButtonShape.setFillColor(sf::Color(143, 188, 219));
                } else {
                    level2Text.setCharacterSize(30);
                }
                if (level3Text.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window)))) {
                    level3Text.setCharacterSize(35);
                    ButtonShape.setFillColor(sf::Color(143, 188, 219));
                } else {
                    level3Text.setCharacterSize(30);
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
    window.draw(backgroundSprite);
    if (currentScreen == Home) {
        drawHomeScreen();
    } else if (currentScreen == Levels) {
        drawLevelsScreen();
    }
    window.display();
}

void GUI::centerTextInButton(sf::Text &text) {
    text.setOrigin(text.getLocalBounds().width / 2, text.getLocalBounds().height / 2);
}

/**
 * @brief Draws the home screen UI components.
 */
void GUI::drawHomeScreen() {
    // window.draw(titleText);

    ButtonShape.setPosition(580, 400);
    window.draw(ButtonShape);
    playText.setPosition(ButtonShape.getPosition());
    window.draw(playText);
}

/**
 * @brief Draws the levels screen UI components.
 */
void GUI::drawLevelsScreen() {
    // window.draw(levelsText);

    backgroundSprite.setTexture(levelBackgroundTexture);
    sf::Vector2u textureSize = levelBackgroundTexture.getSize();
    sf::Vector2u windowSize = window.getSize();
    float scaleX = static_cast<float>(windowSize.x) / textureSize.x;
    float scaleY = static_cast<float>(windowSize.y) / textureSize.y;
    backgroundSprite.setScale(scaleX, scaleY);

    ButtonShape.setPosition(400, 400);
    window.draw(ButtonShape);
    level1Text.setPosition(ButtonShape.getPosition());
    window.draw(level1Text);

    ButtonShape.setPosition(600, 400);
    window.draw(ButtonShape);
    level2Text.setPosition(ButtonShape.getPosition());
    window.draw(level2Text);

    ButtonShape.setPosition(800, 400);
    window.draw(ButtonShape);
    level3Text.setPosition(ButtonShape.getPosition());
    window.draw(level3Text);
}



