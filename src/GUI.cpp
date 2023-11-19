#include "GUI.hpp"

GUI::GUI() {
    initWindow();
    initUI();
}

GUI::~GUI() {
    // Cleanup if needed
}

void GUI::initWindow() {
    window.create(sf::VideoMode(800, 600), "Angry Birds");
}

void GUI::initUI() {
    // Load a font
    font.loadFromFile("path/to/font.ttf");

    // Initialize title text
    titleText.setFont(font);
    titleText.setString("Angry Birds");
    titleText.setCharacterSize(24);
    titleText.setPosition(100, 50);

    // Initialize play button text
    playButton.setFont(font);
    playButton.setString("Play");
    playButton.setCharacterSize(20);
    playButton.setPosition(100, 150);

    // Initialize exit button text
    exitButton.setFont(font);
    exitButton.setString("Exit");
    exitButton.setCharacterSize(20);
    exitButton.setPosition(100, 200);

    // Initialize level selection text
    levelText.setFont(font);
    levelText.setString("Select Level");
    levelText.setCharacterSize(20);
    levelText.setPosition(100, 250);

    // Additional UI setup can be added here
}

void GUI::handleEvents() {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window.close();
        }

        // Add more event handling logic here
    }
}

void GUI::update() {
    // Update logic for animations or UI changes
}

void GUI::render() {
    window.clear();

    // Draw UI elements
    window.draw(titleText);
    window.draw(playButton);
    window.draw(exitButton);
    window.draw(levelText);

    // Additional rendering can be added here

    window.display();
}

void GUI::run() {
    while (window.isOpen()) {
        handleEvents();
        update();
        render();
    }
}
