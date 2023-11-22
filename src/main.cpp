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

TODO: Photoshoppa en slangbella till alla level-bilder, sök samtidigt fram bättre bakgrundsbilder.

TODO: Gör CSV filerna, alltså designa nivåerna.


KODNING:

TODO: Fixa fysiken! Birdie goes brrrrrr när den krockar

TODO: Fixa tiden

TODO: Implementera ett poängsystem, kanske med stjärnor? Gör så att nivån slutar då alla grisar är döda eller då antalet fåglar tagit slut.

TODO: Ge användaren mer än en fågel per nivå. Skapa en ny när den föregående har stannat?

TODO: Implementera bättre damage-logik för grisarna (nu tar dom alltid 10/100 damage för varje kollision).

TODO: Implementera inställningar (settings-bakgrund finns redan). Ge användaren möjligheten att stäga av och lägga på ljud + annat?

TODO: Implementera en ny fågel med en specialattack. Idéer: Klicka en gång på screenen och skjut fågeln mot det stället, gör så att fågeln exploderar, gör så att man kan skjuta iväg fågeln två gånger.
      Implementera i GUI:en en möjlighet att välja fågel före leveln börjar.

TODO: "The view follows the bird as it moves sideways"? Gör världen större och gör så att användarens view följer.

TODO: GUI visar antalet fåglar kvar, mängden poäng, grisar kvar...?

TODO: Lägg till punkter som visar flygbanan för fågeln



EXTRA FEATURES:

TODO: High score list, saved per level, player can enter a nickname (1 point)

TODO: Different game modes: reach goal in time, collect all items, other kind of challenges (2 points) Egna idéer: No gravity mode = lätt.

.
.
.

*/