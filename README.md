# Angry Birds Replica - Happy Birds!

## Overview

Welcome to the Angry Birds Replica project! This is a collaborative effort to create an exciting and challenging game inspired by the Angry Birds franchise. In this game, players will launch birds with a slingshot to knock down structures and defeat pesky pigs.

## Contributors

- **Casper**
- **Linnea**
- **Julius**
- **Matilda**

## Features

- **Physics-based Gameplay:** Experience realistic game physics powered by the Box2D library.

- **Diverse Bird Characters:** Choose two distinct birds, each with its unique special feature.

- **Level Editor:** Unleash your creativity with the built-in level editor.

- **User-Friendly GUI:** The intuitive GUI enhances the gaming experience, and the interface is easy to navigate.

- **Level Creation from CSV Files:** Levels are loaded from CSV files, making the game highly expandable.

- **Soundtrack and Settings:** Create a true gaming atmosphere by turning on the background music.

- **Trajectory Dots:** The trajectory dots makes anyone a precise thrower of birds.

- **No Gravity Gamemode:** Spice up your gameplay by exploring the no gravity gamemode.

- **Different players:** Save a player to save your highest score for every level!

## Getting Started

### Prerequisites

Before running the project, ensure you have the following dependencies installed:

- [SFML](https://www.sfml-dev.org/) for graphics.

[Box2D](https://box2d.org/) is added to the project as a subdirectory and does not have to be downloaded.

### Installation

```bash
# Clone the Repository
git clone https://version.aalto.fi/gitlab/tillanc1/cpp-course-project-angry-birds.git

# Navigate to the Project Directory

# Make a build folder for the project

mkdir build

# Navigate to the Projects build folder

cd build

# Install Dependencies (see ´Prerequisites´)

# Build the project using cmake

cmake ..
make

# Run the project
./AngryBirds
```

## Testing

```bash
# Create a testing folder
mkdir tests

# Navigate to the tests folder inside the build folder
cd tests

# Run the tests
./AngryBirdsTests
```

## Repository Organization

The repository is thoughtfully organized:

- **Source Code:** Find the source code in the `src` folder.
- **Libraries:** The essential libraries are stored in the `libs` folder.
- **Project Plan:** The project plan is in the `plan` folder.
- **Tests:** All tests are organized within the `test` folder.
- **Documentation:** Explore the project documentation in the `doc` folder.
- **Levels:** The csv files that create the levels are in the `Levels` folder.

Additionally, folders with descriptive names have been created to house external files, including sound, backgrounds, pictures and fonts.

## Libraries

The project leverages SFML for graphics and Box2D for physics.

## Working Practices

The group maintains a structured workflow with weekly meetings, documented in the `Meeting-notes.md` file.

## Source Code Documentation

Doxygen is employed for the thorough documentation of the source code.

## Acknowledgements

### Academic Contributions
This project was developed as part of the ELEC-A7151 Object-oriented Programming with C++ course at Aalto University in 2023. We extend our gratitude to Yusein Ali, the course's responsible teacher, and Tuan Anh Nguyen, who served as our project advisor.

### Multimedia Resources
- **Music:** "Fluffing a Duck" by Kevin MacLeod (incompetech.com), licensed under Creative Commons: By Attribution 3.0 License. Available at [chosic.com](https://www.chosic.com/free-music/all/).
- **Background Images:** Created using DALL-E, an AI developed by OpenAI.
- **Font:** Designed by Nate Piekos, available for non-profit use as detailed in 'font info.txt'.

### Image Licenses
- **bird.png:** Licensed under Creative Commons (CC BY-NC 4.0). Available at [freepngimg.com](https://www.freepngimg.com/).
- **specialbird.png:** Licensed under the Creative Commons Attribution-Share Alike License 3.0 (Unported) (CC BY-SA). Featured on [angrybirds.fandom.com](https://angrybirds.fandom.com/).
- **wall.png** and **bog.png:** Sourced from [filterforge.com](https://www.filterforge.com/), permitted for unmodified personal non-commercial use.
- **star.png:** Licensed under the Creative Commons Attribution-NonCommercial 4.0 International Public License. Available at [pngimg.com](https://www.pngimg.com/).
- **sound.png:** Licensed under the CC0 License. Available at [svgrepo.com](https://www.svgrepo.com/).
