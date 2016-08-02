#ifndef BOARD_H
#define BOARD_H

#include "Config.h"

class Counter;
class Displayer;

class Board {
public:
    Board(Displayer *displayer);
    Board(Board &board);
    ~Board();

    Counter *Space(unsigned int x, unsigned int y);
    bool     Move(unsigned int coloumn, unsigned int colour);
    void     DisplayBoard();
    bool     IsFull();

private:
    void initialiseBoard();

private:
    Counter *m_board[WIDTH][HEIGHT];
    Displayer *m_displayer;
};

#endif
