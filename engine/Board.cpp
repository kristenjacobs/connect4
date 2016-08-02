#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include "Board.h"
#include "Counter.h"
#include "Config.h"
#include "NullDisplayer.h"
#include "Displayer.h"

using namespace std;

static NullDisplayer s_nullDisplayer;

Board::Board(Displayer *displayer) :
    m_displayer(displayer) {
    initialiseBoard();
}

Board::Board(Board &board) {
    Counter *counter = NULL;
    initialiseBoard();

    // Copying the contents of the given board....
    for (unsigned int i = 0; i < WIDTH; i++) {
        for (unsigned int j = 0; j < HEIGHT; j++) {
            counter = board.Space(i, j);
            if (counter) {
                Move(i, counter->GetColour()); 
            }     
        }
    }

    // Creates a null displayer because copying the state of the board 
    // should only be required for searching purposes.
    m_displayer = &s_nullDisplayer;
}

Board::~Board() {
}

Counter *Board::Space(unsigned int x, unsigned int y) {
    assert(y < HEIGHT);
    assert(x < WIDTH);

    if (m_board[x][y] != NULL)
        return m_board[x][y];

    return NULL;
}

bool Board::Move(unsigned int column, unsigned int colour) {
    if ((column < 0) || (column >= WIDTH)) {
        m_displayer->DisplayMessage(string("Column number out of bounds"));
        return false;
    }

    // returns false if the column is full.
    if (m_board[column][HEIGHT - 1] != NULL) {
        char message[1024];
        sprintf(message, "Column %u is full\n", column); 
        m_displayer->DisplayMessage(string(message));
        return false;
    }

    for (unsigned int row = HEIGHT - 1; row >= 0; --row) {     
        // if it reaches the bottom or the space below is full ...
        if (row == 0) {
            Counter *counter = new Counter(colour);
            m_board[column][row] = counter;
            break;
        
        } else if (m_board[column][row - 1] != NULL) {
            Counter *counter = new Counter(colour);
            m_board[column][row] = counter;
            break;
        }
    }

    return true;
}

void Board::DisplayBoard() {
    m_displayer->DisplayBoard(*this);
}

bool Board::IsFull() {
    unsigned int topRow = HEIGHT - 1;

    // Goes along the top row, testing if all the spaces are taken.
    for (unsigned int column = 0; column < WIDTH; ++column) {
        if (m_board[column][topRow] == NULL)
            return false;
    }
    return true;
}

void Board::initialiseBoard() {
    for (unsigned int i = 0; i < HEIGHT; i++) {
        for (unsigned int j = 0; j < WIDTH; j++) {
            m_board[j][i] = NULL;
        }
    }    
}

