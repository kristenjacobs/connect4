#ifndef CONSOLE_DISPLAYER_H
#define CONSOLE_DISPLAYER_H

#include "Displayer.h"

class ConsoleDisplayer : public Displayer
{
public:
    ConsoleDisplayer();
    virtual ~ConsoleDisplayer();

    virtual void DisplayBoard(Board &board);
    virtual void DisplayMessage(std::string message);
};

#endif

