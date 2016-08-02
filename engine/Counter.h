#ifndef COUNTER_H
#define COUNTER_H

#include "Counter.h"

class Counter {
public:
    Counter(unsigned int colour);
    ~Counter();

    virtual unsigned int GetColour();

private:
    unsigned int m_colour;
};

#endif
