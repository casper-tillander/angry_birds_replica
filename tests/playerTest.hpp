#ifndef PLAYERTEST_HPP
#define PLAYERTEST_HPP

#include "printer.hpp"
#include "../src/player.hpp"


void testPlayer() {
    Player player("JULIUS");

    std::string message = player.loadFromFile();
    printTestResult(message == "New player: JULIUS", "Load from file for new player");

    player.updateScore(2, 3);
    printTestResult(player.getScoreForLevel(2) == 3, "Update and get score");
}

#endif