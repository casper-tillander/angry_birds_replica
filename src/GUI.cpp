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
    gameOverBackgroundTexture.loadFromFile("../Backgrounds/gameover.png");
    levelCompleteBackgroundTexture.loadFromFile("../Backgrounds/levelcomplete.png");

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

    // Styling and placement for buttons
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

    tryAgainText.setFont(font);
    tryAgainText.setString("Try again");
    tryAgainText.setCharacterSize(30);
    tryAgainText.setFillColor(sf::Color::White);
    tryAgainText.setOrigin(level3Text.getLocalBounds().width / 1.4, level3Text.getLocalBounds().height / 1.3);
    
    
    returnToLevelsText.setFont(font);
    returnToLevelsText.setString("To levels");
    returnToLevelsText.setCharacterSize(30);
    returnToLevelsText.setFillColor(sf::Color::White);
    returnToLevelsText.setOrigin(level3Text.getLocalBounds().width / 1.4, level3Text.getLocalBounds().height / 1.3);

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
        update();
        render();
    }
}

/**
 * @brief Updates the game state.
 */
void GUI::update() {
    if (currentScreen == PlayingLevel) {
        currentLevel->run();
    if (currentLevel->isGameOver()) {
        currentScreen = GameOver;
    } else if (currentLevel->isLevelComplete()) {
        currentScreen = LevelCompleted;
    }
    }
}

/**
 * @brief Launches a specific game level.
 *
 * @param levelNumber The number of the level to launch.
 */
void GUI::launchLevel(int levelNumber) {
    this->levelNumber = levelNumber;
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

        if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
            sf::Vector2f mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window));
            switch (currentScreen) {
                case Home:
                    if (playText.getGlobalBounds().contains(mousePos)) {
                        currentScreen = Levels;
                    }
                    break;
                case Levels:
                    if (level1Text.getGlobalBounds().contains(mousePos)) {
                        launchLevel(1);
                    } else if (level2Text.getGlobalBounds().contains(mousePos)) {
                        launchLevel(2);
                    } else if (level3Text.getGlobalBounds().contains(mousePos)) {
                        launchLevel(3);
                    }
                    break;
                case GameOver:
                case LevelCompleted:
                    if (tryAgainText.getGlobalBounds().contains(mousePos)) {
                        if (currentLevel != nullptr) {
                            launchLevel(levelNumber);
                        }
                    } else if (returnToLevelsText.getGlobalBounds().contains(mousePos)) {
                        currentScreen = Levels;
                    }
                    break;
            }
        }

        if (event.type == sf::Event::MouseMoved) {
            sf::Vector2f mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window));
            switch (currentScreen) {
                case Home:
                    updateButtonHoverEffect(playText, mousePos);
                    break;
                case Levels:
                    updateButtonHoverEffect(level1Text, mousePos);
                    updateButtonHoverEffect(level2Text, mousePos);
                    updateButtonHoverEffect(level3Text, mousePos);
                    break;
                case GameOver:
                case LevelCompleted:
                    updateButtonHoverEffect(tryAgainText, mousePos);
                    updateButtonHoverEffect(returnToLevelsText, mousePos);
                    break;
            }
        }
    }
}

void GUI::updateButtonHoverEffect(sf::Text& buttonText, sf::Vector2f mousePos) {
    if (buttonText.getGlobalBounds().contains(mousePos)) {
        buttonText.setCharacterSize(35);
        ButtonShape.setFillColor(sf::Color(143, 188, 219));
    } else {
        buttonText.setCharacterSize(30);
        ButtonShape.setFillColor(sf::Color(173, 216, 230));
    }
}


/**
 * @brief Renders the game's GUI components.
 */
void GUI::render() {
    window.clear();
    window.draw(backgroundSprite);

    switch (currentScreen) {
        case Home:
            drawHomeScreen();
            break;
        case Levels:
            drawLevelsScreen();
            break;
        case PlayingLevel:
            // Render level gameplay
            break;
        case GameOver:
            drawGameOverScreen();
            break;
        case LevelCompleted:
            drawLevelCompletedScreen();
            break;
    }

    window.display();
}

/**
 * @brief Draws the home screen UI components.
 */
void GUI::drawHomeScreen() {
    ButtonShape.setPosition(580, 400);
    window.draw(ButtonShape);
    playText.setPosition(ButtonShape.getPosition());
    window.draw(playText);
}

/**
 * @brief Draws the levels screen UI components.
 */
void GUI::drawLevelsScreen() {
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


void GUI::drawGameOverScreen() {
    backgroundSprite.setTexture(gameOverBackgroundTexture);

    ButtonShape.setPosition(580, 500);
    window.draw(ButtonShape);
    tryAgainText.setPosition(ButtonShape.getPosition());
    window.draw(tryAgainText);

    ButtonShape.setPosition(580, 400);
    window.draw(ButtonShape);
    returnToLevelsText.setPosition(ButtonShape.getPosition());
    window.draw(returnToLevelsText);
}

void GUI::drawLevelCompletedScreen() {
    backgroundSprite.setTexture(levelCompleteBackgroundTexture);

    ButtonShape.setPosition(560, 400);
    window.draw(ButtonShape);
    returnToLevelsText.setPosition(ButtonShape.getPosition());
    window.draw(returnToLevelsText);
}


