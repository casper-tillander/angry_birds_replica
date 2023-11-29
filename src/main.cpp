#include "game.hpp"

/**
 * @brief The entry point of the program.
 *
 * @return An integer status code indicating the exit status of the program.
 */
int main(){
  Game g;
  g.run();
  return 0;
}

/*
INTE KODNING:

TODO: Photoshoppa en slangbella till alla level-bilder, sök samtidigt fram bättre bakgrundsbilder. (Matilda)

TODO: Gör CSV filerna, alltså designa nivåerna. (Matilda?)


KODNING:

DONE: Fixa buggen med att fåglarna rör på sig när dom är rendered in (Casper)

DONE: Fixa fysiken! Birdie goes brrrrrr när den krockar (Casper)

DONE: Fixa tiden (Casper - fixat, fungerade inte eftersom "Setting vertical sync not supported". Fixade genom att sätta en maximal framerate.)

DONE: Ge användaren mer än en fågel per nivå. Skapa en ny när den föregående har stannat? (Casper)

DONE:  Gör så att nivån slutar då alla grisar är döda eller då antalet fåglar tagit slut. Gör en GUI för detta. (Casper)

DONE: Lägg till en settings - screen (Casper)

DONE: Fix bug: Om man spelar en nivå -> To levels -> Home så ser bakgrunden konstig ut. (Julius)

DONE: Ge användaren möjligheten att stäga av och lägga på ljud (Casper)

DONE: Implementera en ny fågel med en specialattack. Klicka en gång på screenen och skjut fågeln mot det stället. (Casper)

DONE: Implementera i GUI:en en möjlighet att välja fågel före leveln börjar. (Casper)

DONE: Implementera ett poängsystem med stjärnor? (Casper)

DONE: Lägg till punkter som visar flygbanan för fågeln (Casper)

DONE: Implementera bättre damage-logik för grisarna (nu tar dom alltid 10/100 damage för varje kollision). (Julius)

DONE: GUI visar antalet fåglar kvar, grisar kvar? (Julius)

DONE: Different game modes: reach goal in time, collect all items, other kind of challenges (2 points) Egna idéer: No gravity mode = lätt. (Julius)
---------------------------------------------------------------------------------------------------------------

EXTRA FEATURES:

TODO: High score list, saved per level, player can enter a nickname (1 point)

TODO: Level editor to create levels and to save them in a file (4 points) (Liinu)

.
.
.

*/