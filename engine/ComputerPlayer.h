#ifndef COMPUTER_PLAYER_H
#define COMPUTER_PLAYER_H

#include "Config.h"
#include "Player.h"

class Board;
class Displayer;
class Direction;
class BoardEvaluator;
class Game;

class ComputerPlayer : public Player
{
public:
    ComputerPlayer(Displayer *displayer, 
        BoardEvaluator *boardEvaluator);
    virtual ~ComputerPlayer();

    virtual void Move(Board &board);
    virtual void SetColour(Colour colour);
    virtual Colour GetColour() const;
    virtual bool IsMoveValid();

protected:
    int     Search(unsigned int *move,
                   unsigned int depth,
                   Colour colour,
                   Board &board);
    bool    IsEven(unsigned int searchDepth);
    bool    IsFull(Board &board, unsigned int column);
    void    DuplicateBoard(Board &board, Board &searchBoard);
    bool    IsSpecialCase(unsigned int *move, Colour myColour,
                          Colour oppColour, Board &board);

protected:
    Colour          m_colour;
    Colour          m_oppColour;
    Displayer       *m_displayer;
    BoardEvaluator  *m_boardEvaluator;
    unsigned int    m_lastMove;
};

#endif
