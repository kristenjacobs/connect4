#include <stdio.h>
#include <stdlib.h>
#include "ConsoleDisplayer.h"
#include "Config.h"
#include "Board.h"
#include "Counter.h"

using namespace std;

ConsoleDisplayer::ConsoleDisplayer() {
}

ConsoleDisplayer::~ConsoleDisplayer() {
}

void ConsoleDisplayer::DisplayBoard(Board &board) {
    printf("\n\n\n");

    for (unsigned int i = 0; i < WIDTH; i++)
        printf(" ___");
    printf("\n");
    
    for (int y = (HEIGHT - 1); y >= 0; y--) {
        if (y == HEIGHT - 1)
            printf("\n");

        for (unsigned int x = 0; x < WIDTH; x++) {
            if (x == 0)
                printf("|");

            Counter *counter = board.Space(x, y);

            if (counter == NULL)
                printf("   |");
            else if (counter->GetColour() == YELLOW)
                printf(" X |");
            else if (counter->GetColour() == RED)
                printf(" O |");
            else {  
                printf("\nColour not found\n");
                exit(1);
            }
        }

        printf("\n");
        for (int i = 0; i < WIDTH; i++)
            printf(" ___");
        printf("\n\n");
    }
    // Prints the numbers...
    for (int i = 0; i < WIDTH; i++)
        printf("  %u ", i);
    printf("\n\n");
}

void ConsoleDisplayer::DisplayMessage(string message) {
    printf("%s\n", message.c_str());
}
