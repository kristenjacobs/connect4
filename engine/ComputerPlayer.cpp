#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include "Board.h"
#include "BoardEvaluator.h"
#include "ComputerPlayer.h"
#include "Config.h"
#include "Counter.h"
#include "Direction.h"

ComputerPlayer::ComputerPlayer(Displayer *displayer, 
        BoardEvaluator *boardEvaluator) :
    m_boardEvaluator(boardEvaluator),
    m_displayer(displayer),
    m_lastMove(0) {
}

ComputerPlayer::~ComputerPlayer() {
}

void ComputerPlayer::Move(Board &board) {
    unsigned int nextMove;

    if (!IsSpecialCase(&nextMove, m_colour, m_oppColour, board))
        Search(&nextMove, 0, m_oppColour, board);

    assert(nextMove < WIDTH);
    board.Move(nextMove, m_colour);
    m_lastMove = nextMove;
}

void ComputerPlayer::SetColour(Colour colour) {
    m_colour = colour;
    m_oppColour = (m_colour == YELLOW) ? RED : YELLOW;
}

Colour ComputerPlayer::GetColour() const {
    return m_colour;
}

bool ComputerPlayer::IsMoveValid() {
    return true;
}

bool ComputerPlayer::IsSpecialCase(
    unsigned int *move,
    Colour myColour,
    Colour oppColour,
    Board &board) {

    // Special case 1.
    // If I can win now, go for it.
    if (m_boardEvaluator->IsWin(move, board, myColour))
        return true;

    // Special case 2.
    // If the oponent can win now, block it.
    if (m_boardEvaluator->IsWin(move, board, oppColour))
        return true;

    return false;
}

int ComputerPlayer::Search(
    unsigned int *move,
    unsigned int depth,
    Colour colour,
    Board &board) {

    int best = -9999999;
    unsigned int numColumns = WIDTH;

    // If we have reached the bottom of this particular node in the
    // search tree, evaluate the board metric.
    if (depth == SEARCH_DEPTH) {       
        return -(m_boardEvaluator->Evaluate(board, colour));
    }

    // switches the colours each time around.
    if (colour == m_colour)
        colour = m_oppColour;
    else
        colour = m_colour;

    for (unsigned int i = 0; i < numColumns; i++) {
        if (!IsFull(board, i)) {
            // creating and initialising a search board.
            Board searchBoard(m_displayer);
            DuplicateBoard(board, searchBoard);
            
            searchBoard.Move(i, colour);

            int boardValue = -Search(move, depth + 1, colour, searchBoard);

            if (boardValue >= best) {
                best = boardValue;
                *move = i;
            }
        }
    }
    return best;
}

// Function to return true if the given column of the board is full.
bool ComputerPlayer::IsFull(Board &board, unsigned int column) {
    unsigned int topRow = HEIGHT - 1;

    if (board.Space(column, topRow) != NULL)
        return true;
    else
        return false;
}

void ComputerPlayer::DuplicateBoard(Board &board, Board &searchBoard) {
    for (unsigned int y = 0; y < HEIGHT; y++) {
        for (unsigned int x = 0; x < WIDTH; x++) {
            if (board.Space(x, y) != NULL) {
                searchBoard.Move(x, board.Space(x, y)->GetColour());
            }
        }
    }
}

