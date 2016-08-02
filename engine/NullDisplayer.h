#ifndef NULL_DISPLAYER_H
#define NULL_DISPLAYER_H

#include "Displayer.h"

class NullDisplayer : public Displayer {
public:
    NullDisplayer();
    virtual ~NullDisplayer();

    virtual void DisplayBoard(Board &board);
    virtual void DisplayMessage(std::string message);
};

#endif
