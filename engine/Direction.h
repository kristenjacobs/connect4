#ifndef DIRECTION_H
#define DIRECTION_H

class Direction {
public:
    Direction(unsigned int x, unsigned int y);
    ~Direction();

    virtual void Update() = 0;
    unsigned int X();
    unsigned int Y();

protected:    
    bool validate() const;

protected:
    unsigned int m_x;
    unsigned int m_y;
};

class North : public Direction {
public:
    North(unsigned int x, unsigned int y);
    virtual ~North();
    virtual void Update();
};

class South : public Direction {
public:
    South(unsigned int x, unsigned int y);
    virtual ~South();
    virtual void Update();
};

class East : public Direction {
public:
    East(unsigned int x, unsigned int y);
    virtual ~East();
    virtual void Update();
};

class West : public Direction {
public:
    West(unsigned int x, unsigned int y);
    virtual ~West();
    virtual void Update();
};

class NorthEast : public Direction {
public:
    NorthEast(unsigned int x, unsigned int y);
    virtual ~NorthEast();
    virtual void Update();
};

class NorthWest : public Direction {
public:
    NorthWest(unsigned int x, unsigned int y);
    virtual ~NorthWest();
    virtual void Update();
};

class SouthEast : public Direction {
public:
    SouthEast(unsigned int x, unsigned int y);
    virtual ~SouthEast();
    virtual void Update();
};

class SouthWest : public Direction {
public:
    SouthWest(unsigned int x, unsigned int y);
    virtual ~SouthWest();
    virtual void Update();
};

#endif
