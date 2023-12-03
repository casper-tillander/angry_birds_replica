# Unit Tests
  Here are some tests for the foundational classes used in the project. The graphical and more advanced classes can easily be checked by simply playing the game.

## Test of Bird Class

**Involved Classes:**
  Bird

**Test File:**
  birdTest.cpp

**Results:**
  - testBirdConstructor: Checks the initial state of a Bird object after its construction.
  - testLaunch: Verifies the functionality of the launch function.
  - testCalculateTrajectory: Checks the number of trajectory dots generated for the launch.

## Test of SpecialBird Class

**Involved Classes:**
  SpecialBird

**Test File:**
  specialBirdTest.cpp

**Results:**
  - testSpecialBirdConstructor: Checks the initial state of a SpecialBird object after its construction.
  - testSpecialBirdShootTowardsClick: Verifies the functionality of the special ability of the bird.

## Test of Pig Class

**Involved Classes:**
  Pig

**Test File:**
  pigTest.cpp

**Results:**
  - testPigConstructor: Checks the initial state of a Pig object after its construction.
  - testTakeDamage: Verifies that the pig takes damage as expected.
  - testDestroyBody: Ensures that destroying the body of a Pig object affects its state and the ability to take damage.

## Test of Box Class

**Involved Classes:**
  Box

**Test File:**
  boxTest.cpp

**Results:**
  - testBoxConstructor: Checks the initial state of a Box object after its construction.
  - testBoxUpdate: Verifies that the position of the Box object is set correctly.

## Test of Wall Class

**Involved Classes:**
  Wall

**Test File:**
  wallTest.cpp

**Results:**
  - testWallConstructor: Checks the initial state of a Wall object after its construction.
  - testWallUpdate: Verifies that the position of the Wall object is set correctly.

## Test of Readfile Class

**Involved Classes:**
  Readfile

**Test File:**
  readfileTest.cpp

**Results:**
  - testReadFile: Verifies that the readfile creates the objects correctly from a file.
  - testReadEmptyFile: Checks that an empty readfile doesn't create anything.

## Test of Level Class

**Involved Classes:**
  Level, Bird

**Test File:**
  levelTest.cpp

**Results:**
  - testAreAllBirdsUsed: Creates a new world and launches two birds and verifies that there are no birds left.

 ## Test of Player Class

**Involved Classes:**
  Player

**Test File:**
  playerTest.cpp

**Results:**
  - testPlayer: Checks that the displayed message is correct and that the score is updated correctly.