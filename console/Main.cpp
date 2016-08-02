#include <stdio.h>
#include "Config.h"
#include "ConsoleDisplayer.h"
#include "ConsolePlayer.h"
#include "Game.h"

using namespace std;

int main() {
    Displayer *displayer = new ConsoleDisplayer();
    Player *player = new ConsolePlayer(displayer);
    Game game(displayer, player);
    unsigned int winningCol = NULL_COLOUR;

    game.DisplayBoard();
    while (!game.IsFinished(&winningCol)) {
        game.NextMove();
        game.DisplayBoard();
    }

    if (winningCol == NULL_COLOUR) {
        displayer->DisplayMessage(string("Nobody won!!!"));

    } else {
        char message[1024];
        sprintf(message, "The winner was %u\n", winningCol);
        displayer->DisplayMessage(message);
    }
    delete displayer;

    return 0;
}

