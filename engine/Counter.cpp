#include "Counter.h"

Counter::Counter(unsigned int colour) :
    m_colour(colour) {
}

Counter::~Counter() {
}

unsigned int Counter::GetColour() {
    return m_colour;
}

