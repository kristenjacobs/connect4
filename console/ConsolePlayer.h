#ifndef CONSOLE_PLAYER_H
#define CONSOLE_PLAYER_H

#include "Player.h"

class Displayer;

class ConsolePlayer : public Player {
public:
    ConsolePlayer(Displayer *displayer);
    virtual ~ConsolePlayer();

    virtual void Move(Board &board);
    virtual void SetColour(Colour colour);
    virtual Colour GetColour() const;
    virtual bool IsMoveValid();

private:
    Colour m_colour;
    Displayer *m_displayer;
};

#endif
