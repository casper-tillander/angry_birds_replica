#include "GUI.hpp"
#include <iostream>

/**
 * @brief Constructs a GUI object and initializes the game window.
 */
GUI::GUI() : window(sf::VideoMode(1200, 700), "Angry Birds"), currentScreen(Home), currentLevel(nullptr) {
    initialize();
    // Set the initial background
    updateBackground();
}

/**
 * @brief Initializes GUI components, including fonts, textures, and UI elements.
 */
void GUI::initialize() {

    music.openFromFile("../Sound/Fluffing-a-Duck_chosic.com_.ogg");
    music.setLoop(true);
    music.play();
    music.setVolume(10);
    music.pause();
    soundOn = false;

    isSpecialBird = false;

    soundTexture.loadFromFile("../Pictures/sound.png");
    soundButton.setTexture(soundTexture);
    soundButton.setScale(0.5f, 0.5f);

    redLine.setSize(sf::Vector2f(120, 15));
    redLine.setFillColor(sf::Color::Red);
    redLine.setRotation(45);

    // Load necessary resources
    font.loadFromFile("../Fonts/angrybirds-regular.ttf");
    birdTexture.loadFromFile("../Pictures/bird.png");
    mainScreenTexture.loadFromFile("../Backgrounds/homescreen.png");
    levelBackgroundTexture.loadFromFile("../Backgrounds/levels.png");
    gameOverBackgroundTexture.loadFromFile("../Backgrounds/gameover.png");
    levelCompleteBackgroundTexture.loadFromFile("../Backgrounds/levelcomplete.png");
    chooseABirdBackgroundTexture.loadFromFile("../Backgrounds/birdselection.png");
    settingsBackgroundTexture.loadFromFile("../Backgrounds/settings.png");
    specialBirdTexture.loadFromFile("../Pictures/specialbird.png");

    normalBirdButton.setTexture(birdTexture);
    specialBirdButton.setTexture(specialBirdTexture);

    normalBirdButton.setScale(0.05f, 0.05f);
    specialBirdButton.setScale(0.2f, 0.2f);

    // Configure buttons
    setupButton(playText, "Play");
    setupButton(settingsText, "Settings");
    setupButton(returnToHomeText, "Home");
    setupButton(level1Text, "Level 1");
    setupButton(level2Text, "Level 2");
    setupButton(level3Text, "Level 3");
    setupButton(tryAgainText, "Try again");
    setupButton(returnToLevelsText, "To levels");
    setupButton(chooseBirdText, "Choose Bird");

    // Styling and placement for buttons
    returnToHomeText.setOrigin(returnToHomeText.getLocalBounds().width / 2, returnToHomeText.getLocalBounds().height / 1.3);
    settingsText.setOrigin(settingsText.getLocalBounds().width / 2, settingsText.getLocalBounds().height / 1.3);
    playText.setOrigin(playText.getLocalBounds().width / 2, playText.getLocalBounds().height / 1.3);
    level1Text.setOrigin(level1Text.getLocalBounds().width / 2, level1Text.getLocalBounds().height / 1.3);
    level2Text.setOrigin(level2Text.getLocalBounds().width / 2, level2Text.getLocalBounds().height / 1.3);
    level3Text.setOrigin(level3Text.getLocalBounds().width / 2, level3Text.getLocalBounds().height / 1.3);
    tryAgainText.setOrigin(level3Text.getLocalBounds().width / 1.4, level3Text.getLocalBounds().height / 1.3);
    returnToLevelsText.setOrigin(level3Text.getLocalBounds().width / 1.4, level3Text.getLocalBounds().height / 1.3);
    chooseBirdText.setOrigin(chooseBirdText.getLocalBounds().width / 2, chooseBirdText.getLocalBounds().height / 1.3);

    // Configure circular button shape
    ButtonShape.setRadius(30);
    ButtonShape.setScale(3, 1);
    ButtonShape.setFillColor(sf::Color(173, 216, 230));
    ButtonShape.setOutlineThickness(1);
    ButtonShape.setOutlineColor(sf::Color::White);
    ButtonShape.setOrigin(ButtonShape.getLocalBounds().width / 2, ButtonShape.getLocalBounds().height / 2);

    // Selection circle for birds.
    highlightCircle.setRadius(60);
    highlightCircle.setFillColor(sf::Color::Transparent);
    highlightCircle.setOutlineColor(sf::Color::White);
    highlightCircle.setOutlineThickness(5);

    // Stars for point system
    starTexture.loadFromFile("../Pictures/star.png");
    starSprite.setTexture(starTexture);
    starSprite.setScale(0.9f, 0.9f);

    
}

void GUI::updateBackground() {
    sf::Texture* currentTexture = nullptr;
    switch (currentScreen) {
        case Home:
            currentTexture = &mainScreenTexture;
            break;
        case Levels:
            currentTexture = &levelBackgroundTexture;
            break;
        case GameOver:
            currentTexture = &gameOverBackgroundTexture;
            break;
        case LevelCompleted:
            currentTexture = &levelCompleteBackgroundTexture;
            break;
        case Settings:
            currentTexture = &settingsBackgroundTexture;
            break;
        case BirdSelection:
            currentTexture = &chooseABirdBackgroundTexture;
            break;
        
    }

    if (currentTexture) {
        backgroundSprite.setTexture(*currentTexture);
        textureSize = currentTexture->getSize();
        windowSize = window.getSize();
        float scaleX = static_cast<float>(windowSize.x) / textureSize.x;
        float scaleY = static_cast<float>(windowSize.y) / textureSize.y;
        backgroundSprite.setScale(scaleX, scaleY);
    }
}


void GUI::setupButton(sf::Text& buttonText, const std::string& text) {
    buttonText.setFont(font);
    buttonText.setString(text);
    buttonText.setCharacterSize(30);
    buttonText.setFillColor(sf::Color::White);
}

/**
 * @brief Updates the button hover effect.
 *
 * @param buttonText The text of the button.
 * @param mousePos The current mouse position.
 */
void GUI::updateButtonHoverEffect(sf::Text& buttonText, sf::Vector2f mousePos) {
    if (buttonText.getGlobalBounds().contains(mousePos)) {
        buttonText.setCharacterSize(35);
    } else {
        buttonText.setCharacterSize(30);
    }
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
    currentLevel = new Level(window, levelNumber, backgroundTexture, levelFile, isSpecialBird);
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
                    } else if (settingsText.getGlobalBounds().contains(mousePos)) {
                        currentScreen = Settings;
                    } else if (chooseBirdText.getGlobalBounds().contains(mousePos)) {
                        currentScreen = BirdSelection;
                    }
                    break;
                case Levels:
                    if (returnToHomeText.getGlobalBounds().contains(mousePos)) {
                        currentScreen = Home;
                    } else if (level1Text.getGlobalBounds().contains(mousePos)) {
                        launchLevel(1);
                    } else if (level2Text.getGlobalBounds().contains(mousePos)) {
                        launchLevel(2);
                    } else if (level3Text.getGlobalBounds().contains(mousePos)) {
                        launchLevel(3);
                    }
                    break;
                case GameOver:
                    if (tryAgainText.getGlobalBounds().contains(mousePos)) {
                        if (currentLevel != nullptr) {
                            launchLevel(levelNumber);
                        }
                    } else if (returnToLevelsText.getGlobalBounds().contains(mousePos)) {
                        currentScreen = Levels;
                    }
                    break;

                case LevelCompleted:
                    if (returnToLevelsText.getGlobalBounds().contains(mousePos)) {
                        currentScreen = Levels;
                    }
                    break;
                case Settings:
                    if (returnToHomeText.getGlobalBounds().contains(mousePos)) {
                        currentScreen = Home;
                    } else if (soundButton.getGlobalBounds().contains(mousePos)) {
                        if (soundOn) {
                            music.pause();
                            soundOn = false;
                        } else {
                            music.play();
                            soundOn = true;
                        }
                    }
                    break;
                case BirdSelection:
                if (normalBirdButton.getGlobalBounds().contains(mousePos)) {
                    isSpecialBird = false;
                } else if (specialBirdButton.getGlobalBounds().contains(mousePos)) {
                    isSpecialBird = true;
                } else if (returnToHomeText.getGlobalBounds().contains(mousePos)) {
                        currentScreen = Home;
                }
                break;
            }
        }

        if (event.type == sf::Event::MouseMoved) {
            sf::Vector2f mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window));
            switch (currentScreen) {
                case Home:
                    updateButtonHoverEffect(playText, mousePos);
                    updateButtonHoverEffect(settingsText, mousePos);
                    updateButtonHoverEffect(chooseBirdText, mousePos);
                    break;
                case Levels:
                    updateButtonHoverEffect(level1Text, mousePos);
                    updateButtonHoverEffect(level2Text, mousePos);
                    updateButtonHoverEffect(level3Text, mousePos);
                    updateButtonHoverEffect(returnToHomeText, mousePos);
                    break;
                case GameOver:
                    updateButtonHoverEffect(tryAgainText, mousePos);
                    updateButtonHoverEffect(returnToLevelsText, mousePos);
                case LevelCompleted:
                    updateButtonHoverEffect(returnToLevelsText, mousePos);
                    break;
                case Settings:
                    updateButtonHoverEffect(returnToHomeText, mousePos);
                    break;
                case BirdSelection:
                    updateButtonHoverEffect(returnToHomeText, mousePos);
                    break;
            }
        }
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
        case Settings:
            drawSettingsScreen();
            break;
        case BirdSelection:
            drawBirdSelectionScreen();
            break;
    }

    window.display();
}

/**
 * @brief Draws the home screen UI components.
 */
void GUI::drawHomeScreen() {
    updateBackground();
    ButtonShape.setPosition(400, 400);
    window.draw(ButtonShape);
    playText.setPosition(ButtonShape.getPosition());
    window.draw(playText);

    ButtonShape.setPosition(600, 400);
    window.draw(ButtonShape);
    settingsText.setPosition(ButtonShape.getPosition());
    window.draw(settingsText);

    ButtonShape.setPosition(800, 400); 
    window.draw(ButtonShape);
    chooseBirdText.setPosition(ButtonShape.getPosition());
    window.draw(chooseBirdText);
}

/**
 * @brief Draws the levels screen UI components.
 */
void GUI::drawLevelsScreen() {
    updateBackground();
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

    ButtonShape.setPosition(100, 50);
    window.draw(ButtonShape);
    returnToHomeText.setPosition(ButtonShape.getPosition());
    window.draw(returnToHomeText);
}

/**
 * @brief Draws the game over screen UI components.
 */
void GUI::drawGameOverScreen() {
    updateBackground();
    ButtonShape.setPosition(580, 500);
    window.draw(ButtonShape);
    tryAgainText.setPosition(ButtonShape.getPosition());
    window.draw(tryAgainText);

    ButtonShape.setPosition(580, 400);
    window.draw(ButtonShape);
    returnToLevelsText.setPosition(ButtonShape.getPosition());
    window.draw(returnToLevelsText);
}

/**
 * @brief Draws the level completed screen UI components.
 */
void GUI::drawLevelCompletedScreen() {
    updateBackground();
    ButtonShape.setPosition(575, 550);
    window.draw(ButtonShape);
    returnToLevelsText.setPosition(ButtonShape.getPosition());
    window.draw(returnToLevelsText);

    // Draw stars based on birds used
    if (currentLevel != nullptr) {
    int birdsUsed = currentLevel->getBirdsUsedForCompletion();
    int totalBirds = 3;
    int starsToDisplay = totalBirds - birdsUsed + 1;

    for (int i = 0; i < starsToDisplay; i++) {
        starSprite.setPosition(265 + i * 200, 280);
        window.draw(starSprite);
    }
}

}

/**
 * @brief Draws the settings screen.
 */
void GUI::drawSettingsScreen() {
    updateBackground();
    
    ButtonShape.setPosition(100, 50);
    window.draw(ButtonShape);
    returnToHomeText.setPosition(ButtonShape.getPosition());
    window.draw(returnToHomeText);

    soundButton.setPosition(530, 350);
    window.draw(soundButton);

    if (!soundOn) {
        redLine.setPosition(soundButton.getPosition().x + soundButton.getGlobalBounds().width / 5,
                            soundButton.getPosition().y + soundButton.getGlobalBounds().height / 8);
        window.draw(redLine);
    }
}

void GUI::drawBirdSelectionScreen() {
    updateBackground();

    ButtonShape.setPosition(100, 50);
    window.draw(ButtonShape);
    returnToHomeText.setPosition(ButtonShape.getPosition());
    window.draw(returnToHomeText);

    normalBirdButton.setPosition(475, 450);
    window.draw(normalBirdButton);

    specialBirdButton.setPosition(585, 450);
    window.draw(specialBirdButton);

    // Update highlightCircle position based on the selected bird
    sf::Vector2f birdButtonCenter;
    if (isSpecialBird) {
        birdButtonCenter = sf::Vector2f(specialBirdButton.getPosition().x + specialBirdButton.getGlobalBounds().width / 2,
                                        specialBirdButton.getPosition().y + specialBirdButton.getGlobalBounds().height / 2);
    } else {
        birdButtonCenter = sf::Vector2f(normalBirdButton.getPosition().x + normalBirdButton.getGlobalBounds().width / 2,
                                        normalBirdButton.getPosition().y + normalBirdButton.getGlobalBounds().height / 2);
    }
    highlightCircle.setPosition(birdButtonCenter.x - highlightCircle.getRadius(), 
                                birdButtonCenter.y - highlightCircle.getRadius());

    window.draw(highlightCircle);
}

