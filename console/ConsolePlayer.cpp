#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "ConsolePlayer.h"
#include "Board.h"
#include "Displayer.h"

using namespace std;

ConsolePlayer::ConsolePlayer(Displayer *displayer) :
    m_displayer(displayer) {
}

ConsolePlayer::~ConsolePlayer() {
}

void ConsolePlayer::Move(Board &board) {
    int columnNum = 0;
    do {
        char message[1024];
        sprintf(message, "player %u move: ", m_colour);
        m_displayer->DisplayMessage(string(message));

        char column[4];
        fgets(column, sizeof(column), stdin);
    
        columnNum = atoi(column);

    } while(!board.Move(columnNum, m_colour));
}

void ConsolePlayer::SetColour(Colour colour) {
    m_colour = colour;
}

Colour ConsolePlayer::GetColour() const {
    return m_colour;
}

bool ConsolePlayer::IsMoveValid() {
    return true;
}

