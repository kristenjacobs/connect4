#ifndef CON4_CONFIG_H
#define CON4_CONFIG_H

enum Colour {
    YELLOW = 0,
    RED,
    NULL_COLOUR = 9999,
};

enum PlayerType {
    HUMAN = 0,
    COMPUTER = 1,
    STEPPED_COMPUTER = 2
};

#define WIDTH 8
#define HEIGHT 8
#define CONNECT_LENGTH 4
#define GEN_WEIGHT 10
#define SEARCH_DEPTH 2
#define PLAYER_TYPE_0 HUMAN
#define PLAYER_TYPE_1 STEPPED_COMPUTER

#endif
