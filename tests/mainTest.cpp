#include "birdTest.hpp"
#include "specialBirdTest.hpp"
#include "pigTest.hpp"
#include "boxTest.hpp"
#include "wallTest.hpp"
#include "readfileTest.hpp"
#include "levelTest.hpp"
#include "playerTest.hpp"

int main() {
    // Bird tests
    testBirdConstructor();
    testLaunch();
    testCalculateTrajectory();

    // Special Bird tests
    testSpecialBirdConstructor();
    testSpecialBirdShootTowardsClick();

    // Pig tests
    testPigConstructor();
    testTakeDamage();
    testDestroyBody();
    
    // Box tests
    testBoxConstructor();
    testBoxUpdate();
    
    // Wall tests
    testWallConstructor();
    testWallUpdate();

    // Readfile tests
    testReadFile();
    testReadEmptyFile();
   
    // Level test
    testAreAllBirdsUsed();

    // Player test
    testPlayer();

    printResults();
    return 0;
}
