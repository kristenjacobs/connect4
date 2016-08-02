#include <assert.h>
#include "Config.h"
#include "Direction.h"

Direction::Direction(unsigned int x, unsigned int y) :
    m_x(x),
    m_y(y) {
}
    
Direction::~Direction() {
}

unsigned int Direction::X() {
    return m_x;
}

unsigned int Direction::Y() {
    return m_y;
}

bool Direction::validate() const {
    return (m_y >= 0) &&
           (m_y < HEIGHT) &&
           (m_x >= 0) &&
           (m_x < WIDTH);
}

North::North(unsigned int x, unsigned int y) :
    Direction(x, y) {
}

North::~North() {
}

void North::Update() {
    m_y++;
}

South::South(unsigned int x, unsigned int y) :
    Direction(x, y) {
}

South::~South() {
}

void South::Update() {
    assert(validate());
    m_y--;
}

East::East(unsigned int x, unsigned int y) :
    Direction(x, y) {
}

East::~East() {
}

void East::Update() {
    assert(validate());
    m_x++;
}

West::West(unsigned int x, unsigned int y) :
    Direction(x, y) {
}

West::~West() {
}

void West::Update() {
    assert(validate());
    m_x--;
}

NorthEast::NorthEast(unsigned int x, unsigned int y) :
    Direction(x, y) {
}

NorthEast::~NorthEast() {
}

void NorthEast::Update() {
    assert(validate());
    m_y++;
    m_x++;
}

SouthEast::SouthEast(unsigned int x, unsigned int y) :
    Direction(x, y) {
}

SouthEast::~SouthEast() {
}

void SouthEast::Update() {
    assert(validate());
    m_y--;
    m_x++;
}

NorthWest::NorthWest(unsigned int x, unsigned int y) :
    Direction(x, y) {
}

NorthWest::~NorthWest() {
}

void NorthWest::Update() {
    assert(validate());
    m_y++;
    m_x--;
}

SouthWest::SouthWest(unsigned int x, unsigned int y) :
    Direction(x, y) {
}

SouthWest::~SouthWest() {
}

void SouthWest::Update() {
    assert(validate());
    m_x--;
    m_y--;
}

