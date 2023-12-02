#include "birdTest.hpp"
#include "specialBirdTest.hpp"
#include "pigTest.hpp"
#include "boxTest.hpp"
#include "wallTest.hpp"
#include "readfileTest.hpp"

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
    testReadValidFile(); // Fails
    testReadInvalidData(); // Fails
    testReadEmptyFile();
   

    printResults();
    return 0;
}
