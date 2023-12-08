# Meeting Notes

# Meeting 25.10.2023 10:00

**Participants**: 
1. Linnea
2. Matilda
3. Casper
4. Julius

## Summary of works
- Casper created the respository.
- Divided the work for the Project Plan, as a group. 
- Discussed the implementation of the project in broad terms. 
- No work was done before the meeting, as this is the first one. 

## Challenges
- Come up with relevant classes.
- Figure out how to implement the graphics.
- Familiarize ourself with the external libraries.

## Actions
- Linnea is going to work on the UML model of the project.
- Matilda is going to work on figuring out relevant classes and their members and methods.
- Casper and Julius are going to work on the project plan in general and figure out the scope and the schedule aswell.

## Project status
Currently, we have created the repository and started on the project plan. The project plan should be finnished before the next meeting.

### TODOs
- Linnea is going to finish the UML model.
- Matilda is going to work on the structure of the project and explain it in the project plan.
- Casper and Julius is going to finish the other parts of the project plan.

# Meeting 1.11.2023 10:00
Short meeting where we decided that we try to complete our other coursework before starting on the project.

# Meeting 8.11.2023 11:00
Short meeting where we decided that we try to complete our other coursework before starting on the project.

# Meeting 18.11.2023 10:00

**Participants**: 
1. Linnea
2. Matilda
3. Casper
4. Julius

## Summary of works
1. Casper 
   
   - Added Box2D to the project, integrated SFML and Box2D in the project using a cMakeLists.txt file. 
   - Created a testfile to prove that both libraries work.

2. Linnea

   - Added SFML to the project.

## Challenges
- Integration of the libraries proved surprisingly difficult, because of a bug in the current version of SFML.
   - This probelm was solved by having all participants download SFML instead of adding it as a submodule.

## Actions
- Linnea is going to fix the merge-errors by adding nessecary files to gitignore.
- Casper is going to start working on the project.

## Project status
All the necessary libraries are included and working.

### TODOs
- Linnea is going to fix the merge-errors by adding nessecary files to gitignore.
- Casper is going to start working on the project.

# Meeting 22.11.2023 11:00

**Participants**: 
1. Linnea
2. Matilda
3. Casper
4. Julius

## Summary of works
1. Casper 
   
   - Implemented the basic GUI, including a homescreen and a levels-screen.
   - Added several object-classes, started implementing the logic for levels and birds.
   - Added a pig class and launch logic for the bird.
   - Added two object classes, box and wall. Box is dynamic, wall is static. Also changed the size of the window and some styling.
   - Added a file that reads csv-files, and then implemented functionality for creating levels from csv-files.
   - Added three simple levels.
   - Implemented a damage system for pigs, using a collisiondetection class.
   - Integrated doxygen into the project and generated documentation. Added a Doxyfile.
   - Fixed the scaling issues, as well as the center of mass - issues.
   - Fixed issues with the game running differently on different computers.
   - Implemented 3 birds/level.
   - Fixed bug with bird rendering.
   - Added game over and game completed - logic as well as the ability to return back to levels and try again.
   - Added Doxygen comments to the whole project.
   - Added settings - screen, simplified the GUI.
   - Added backgroundmusic as wel as the ability to turn it off.

2. Linnea

   - Added necessary files to gitignore, solving the problem of always having to merge unessessary files.

3. Julius

   - Fixed a bug that made the scaling of the screen fail when returning to the homescreen after playing a level.

## Challenges

- The game ran at different speeds on different computers
  - This was fixed by settign a maximum framerate.
- We had a problem with having to merge unessessary files.
   - They where added to gitignore.
- We had a bug that made the scaling of the screen fail when returning to the homescreen after playing a level.
   - This was solved by deleting some duplicated code.
- SFML and Box2D use different coordinates, which in the beginning made a lot of problems.
   - In the future, syncronising the coordinate
systems might be a good idea, but for now, this was solved by manual scaling.

## Actions
- Linnea is going to make a level editor.
- Julius is going to make a gamemode (no gravity).
- Julius is going to make the GUI include statistics.
- Julius is going to implement better damage-logic for the pigs.
- Matilda is going to edit the backgrounds so that they include a slingshot. 
- Matilda is going to try and find and edit better background pictures.
- Casper is going to implement a spacial bird and the ability to switch between birds.
- Casper is going to implement a point system using stars.
- Casper is going to implement trajectory dots to the birds.

## Project status
Most of basic game is completed, but some features are still missing, and some additional features are to be implemented.

### TODOs
- Linnea is going to make a level editor.
- Julius is going to make a gamemode (no gravity).
- Julius is going to make the GUI include statistics.
- Julius is going to implement better damage-logic for the pigs.
- Matilda is going to edit the backgrounds so that they include a slingshot. 
- Matilda is going to try and find and edit better background pictures.
- Casper is going to implement a special bird and the ability to switch between birds.
- Casper is going to implement a point system using stars.
- Casper is going to implement trajectory dots to the birds.

# Meeting 30.11.2023 20:00

**Participants**: 
1. Linnea
2. Matilda
3. Casper
4. Julius

## Summary of works
1. Casper 
   
   - Implemented a special bird and the ability to switch between birds.
   - Implemented a point system using stars.
   - Implemented trajectory dots for the birds.

2. Linnea

   - Started working on the level editor, implemented the ability to choose between backgrounds.

3. Julius

   - Made a new gamemode, no gravity and implemented the ability to switch it on and off in settings.
   - Updated the damage-logic for the pigs.
   - Included statistics in the level GUI.

4. Matilda

   - Added new backgrounds with slingshots photoshopped into them.
   

## Challenges
- The level editor seems to be a bit harder to implement than some of the other features.
   - Linnea will keep working on this and ask for help if necessary.

## Actions
- Matilda is going to implement a system that saves the stars of each player to an external files, and reloads them when the player enters their nickname.
- Matilda is going to make better csv-files.
- Linnea is going to finnish the level editor and start working on the documentation.
- Julius is going to create tests for the application.
- Casper is going to go through the code to make sure it is working perfectly.
- Casper is going to make doxygen-compatible comments for all files and create the final documentation for the source code.

## Project status
The game is completed, but we still want to add some additional features. The documentation (except for doxygen) is still to be created as well as the testing.

### TODOs
- Matilda is going to implement a system that saves the stars of each player to an external files, and reloads them when the player enters their nickname.
- Matilda is going to make better csv-files.
- Linnea is going to finnish the level editor and start working on the documentation.
- Julius is going to create tests for the application.
- Casper is going to go through the code to make sure it is working perfectly.
- Casper is going to make doxygen-compatible comments for all files and create the final documentation for the source code.
- Casper is going to translate the meeting notes to markdown syntax and push them.

# Meeting 4.12.2023 12.00 (Planned meeting, participants can add their own summary before the meeting.)

**Participants**: 
1. Linnea
2. Matilda
3. Casper
4. Julius

## Summary of works
1. Casper 
   
   - Translated meeting notes to markdown syntax.
   - Fixed potential valgrind error.
   - Made small updates to the level graphics (ground position and trajectory dots).
   - Made the final readme-file.
   - Implemented a system that saves the stars of each player to an external files, and reloads them when the player enters
   their nickname. The stars are then printed next to the levels.
   - Made or updated individual readme files for all folders in the project, except for src and tests.

2. Linnea

3. Julius

4. Matilda
   - Continued on level csv files.
   

## Challenges

- Potential valgrind errors.
   - Turned out to be related to an old version of wsl.


## Actions
- Matilda is going to make final doxygen-compatible comments for all files.

## Project status


### TODOs
- Matilda is going to make final doxygen-compatible comments for all files.