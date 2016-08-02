#include <math.h>
#include <stdlib.h>
#include "BoardEvaluator.h"
#include "Board.h"
#include "Config.h"
#include "Board.h"
#include "Direction.h"
#include "Counter.h"

bool BoardEvaluator::IsWin(unsigned int *move, Board &board, unsigned int col) {   
    Board *boardPtr = &board;
    Colour winningColour = NULL_COLOUR;

    // Try each column in turn, and see if it produces a winner....
    for (unsigned int i = 0; i < WIDTH; i++) {
        Board tempBoard(*((Board *)boardPtr)); 

        tempBoard.Move(i, col);

        IsFinished(tempBoard, &winningColour);

        if (winningColour == (Colour)col) {
            *move = i;
            return true;
        }
    }
    return false;
}

int BoardEvaluator::Evaluate(Board &board, unsigned int colour) {
    unsigned int x;
    unsigned int y;

    int boardValue = 0;

    // Evaluate the vertical lines.
    for (x = 0; x < WIDTH; x++) {
        for (y = 0; y <= (HEIGHT - CONNECT_LENGTH); y++) {
            North dir(x, y);
            boardValue += AllOneColour(board, colour, dir);
        }
    }
    
    // Evaluate the horizontal lines.
    for (y = 0; y < HEIGHT; y++) {
        for (x = 0; x <= (WIDTH - CONNECT_LENGTH); x++) {
            East dir(x, y);
            boardValue += AllOneColour(board, colour, dir);
        }
    }   

    // Evaluate bottom left to top right.
    for (x = 0; x <= (WIDTH - CONNECT_LENGTH); x++) {
        for (y = 0; y <= (HEIGHT - CONNECT_LENGTH - x); y++) {
            NorthEast dir(x + y, y);
            boardValue += AllOneColour(board, colour, dir);         
        }
    }
    for (y = 1; y <= (HEIGHT - CONNECT_LENGTH); y++) {
        for (x = 0; x <= (HEIGHT - CONNECT_LENGTH - y); x++) {
            NorthEast dir(x + y, y);
            boardValue += AllOneColour(board, colour, dir);         
        }
    }   

    // Evaluate bottom right to top left.
    for (x = (WIDTH - 1); x >= (WIDTH - 1 - CONNECT_LENGTH); x--) {
        for (y = 0; y < (x - 2); y++) {
            NorthWest dir(x - y, y);
            boardValue += AllOneColour(board, colour, dir);         
        }
    }
    for (y = 1; y <= (HEIGHT - CONNECT_LENGTH); y++) {
        for (x = 0; x <= (HEIGHT - CONNECT_LENGTH - y); x++) {
            NorthEast dir(x, y + x);
            boardValue += AllOneColour(board, colour, dir);         
        }
    }   
    return boardValue;
}

// Function to check if there are any of the oppositions counters in a given row.
unsigned int BoardEvaluator::AllOneColour(
    Board &board, 
    unsigned int colour,
    Direction &dir) {

    unsigned int lineValue = 0;
    for (unsigned int i = 0; i < CONNECT_LENGTH; i++) {
        if (board.Space(dir.Y(), dir.X()) != NULL) {
            if (board.Space(dir.Y(), dir.X())->GetColour() != colour)
                return 0;
            else
                lineValue++;
        }
        dir.Update();
    }

    // TODO: take account of the weightings.
    unsigned int retVal = (unsigned int)pow(lineValue, GEN_WEIGHT);

    return retVal;
}

bool BoardEvaluator::IsFinished(Board &board, Colour *winningColour) {
    for (unsigned int i = 0; i < WIDTH; i++) {
        for (unsigned int j = 0; j < HEIGHT; j++) {
            Counter *counter = board.Space(i, j);
            
            if (counter != NULL) {
                // creating the dirctions to be searched in.
                North       north(i, j);
                South       south(i, j);
                East        east(i, j);
                West        west(i, j);
                NorthEast   northEast(i, j);
                NorthWest   northWest(i, j);
                SouthEast   southEast(i, j);
                SouthWest   southWest(i, j);

                bool retVal             = false;
                Colour retCol           = NULL_COLOUR;
                unsigned int conLength  = CONNECT_LENGTH;
                Colour colour           = (Colour)counter->GetColour();

                if (RecursiveSearch(colour, &north, conLength - 1, board)) {
                    retCol = colour;
                    retVal = true;
                }
                if (RecursiveSearch(colour, &south, conLength - 1, board)) {
                    retCol = colour;
                    retVal = true;
                }
                if (RecursiveSearch(colour, &east, conLength - 1, board)) {
                    retCol = colour;
                    retVal = true;
                }
                if (RecursiveSearch(colour, &west, conLength - 1, board)) {
                    retCol = colour;
                    retVal = true;
                }
                if (RecursiveSearch(colour, &northEast, conLength - 1, board)) {
                    retCol = colour;
                    retVal = true;
                }
                if (RecursiveSearch(colour, &northWest, conLength - 1, board)) {
                    retCol = colour;
                    retVal = true;
                }
                if (RecursiveSearch(colour, &southEast, conLength - 1, board)) {
                    retCol = colour;
                    retVal = true;
                }
                if (RecursiveSearch(colour, &southWest, conLength - 1, board)) {
                    retCol = colour;
                    retVal = true;
                }
                
                if (retVal) {
                    *winningColour = retCol;
                    return true;
                }
            }
        }
    }           
    return false;
}

bool BoardEvaluator::RecursiveSearch(
    Colour colour, Direction *dir, 
    unsigned int counter, Board &board) {

    if (board.Space(dir->X(), dir->Y()) == NULL)
        return false;

    Colour currentColour = (Colour)board.Space(dir->X(), dir->Y())->GetColour();

    if (currentColour != colour)
        return false;

    if (counter == 0)
        return true;
                
    dir->Update();

    // Check to see if the side of the board isnt reached.
    if ((dir->X() < 0) || (dir->X() >= WIDTH))
        return false;

    if ((dir->Y() < 0) || (dir->Y() >= HEIGHT))
        return false;
    
    counter--;

    return RecursiveSearch(colour, dir, counter, board);
}

