#ifndef BOARD_EVALUATOR_H
#define BOARD_EVALUATOR_H

#include "BoardEvaluator.h"
#include "Config.h"

class Board;
class Direction;

class BoardEvaluator {
public:
    int Evaluate(Board &board, unsigned int colour);
    bool IsWin(unsigned int *move, Board &board, unsigned int col);
    bool IsFinished(Board &board, Colour *winningColour);

private:
    unsigned int AllOneColour(Board &board, unsigned int colour, Direction &dir);
    bool         RecursiveSearch(Colour colour, Direction *dir, 
                                 unsigned int counter, Board &board);
};

#endif
