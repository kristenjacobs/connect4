#include <stdio.h>
#include "ComputerPlayer.h"
#include "Game.h"
#include "Config.h"
#include "Counter.h"
#include "Player.h"
#include "Direction.h"
#include "BoardEvaluator.h"

Game::Game(Displayer *displayer, Player *humanPlayer) :
    m_displayer(displayer),
    m_board(displayer),
    m_currentPlayer(0),
    m_humanPlayer(humanPlayer),
    m_computerPlayer(new ComputerPlayer(m_displayer, &m_boardEvaluator)) {

    m_humanPlayer->SetColour(YELLOW);
    m_computerPlayer->SetColour(RED);
}

Game::~Game() {
    delete m_computerPlayer;
}

void Game::NextMove() {
    Player *player = getCurrentPlayer();
    player->Move(m_board);
    if (player->IsMoveValid())
        updateCurrentPlayer();
}

bool Game::IsFinished(unsigned int *winningColour) {
    if (m_board.IsFull()) {
        *winningColour = NULL_COLOUR;
        return true;
    }
    return m_boardEvaluator.IsFinished(m_board, (Colour *)winningColour);
}

void Game::DisplayBoard() {
    m_board.DisplayBoard();
}

Board &Game::getBoard() {
    return m_board;
}

Player *Game::getCurrentPlayer() {
    return m_currentPlayer == 0 ? m_humanPlayer : m_computerPlayer;
}

void Game::updateCurrentPlayer() {
    m_currentPlayer = (m_currentPlayer == 0) ? 1 : 0;
}

