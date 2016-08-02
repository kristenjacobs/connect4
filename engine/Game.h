#ifndef GAME_H
#define GAME_H

#include "Board.h"
#include "BoardEvaluator.h"
#include "Config.h"
#include "Game.h"

class Direction;
class Displayer;
class Player;

class Game {
public:
    Game(Displayer *displayer, Player *humanPlayer);
    ~Game();

    void NextMove();
    bool IsFinished(unsigned int *winningColour);
    void DisplayBoard();
    Board &getBoard();

private:
    Player *getCurrentPlayer();
    void updateCurrentPlayer();

private:
    Player *m_humanPlayer;
    Player *m_computerPlayer;
    unsigned int m_currentPlayer;
    Board m_board;
    Displayer *m_displayer;
    BoardEvaluator m_boardEvaluator;
};

#endif
