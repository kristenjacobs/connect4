#ifndef PLAYER_H
#define PLAYER_H

#include "Config.h"

class Board;

class Player {
public:
    virtual void Move(Board &board) = 0;
    virtual void SetColour(Colour colour) = 0;
    virtual Colour GetColour() const = 0;
    virtual bool IsMoveValid() = 0;
};

#endif
