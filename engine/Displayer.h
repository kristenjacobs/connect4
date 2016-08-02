#ifndef DISPLAYER_H
#define DISPLAYER_H

#include <string>

class Board;

class Displayer
{
public:
    virtual void DisplayBoard(Board &board) = 0;
    virtual void DisplayMessage(std::string message) = 0;
};

#endif
