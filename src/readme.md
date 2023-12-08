# Source content

A brief summary of all classes. UML diagram showing the class relations can be found in the project documentation.

### Game
Encapsulates the main control logic for a game and executes the game loop.

### GUI
Manages the game's graphical user interface.

### Level
Constructs levels according to the information of a CSV file. Includes physics simulation.

### ReadFile
Reads the CSV file containing level information.

### Player
Represents a user who has logged in to the game and saves scores for the user.

### LevelEditor
Enables users to create their own levels by placing desired items to desired locations.

### CollisionDetection
Handles collisions and contact events in the game.

### Bird
Represents the bird in the game that is launched towards the fortress.

### SpecialBird
Represents the bird with the special attack feature. Inherits from Bird class.

### Pig 
Represents the pig in the game, which is the enemy to be destroyed.

### Box
Represents a movable box object in the game.

### Wall
Represents an immovable wall object in the game.
