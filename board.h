#ifndef BOARD_H_INCLUDED
#define BOARD_H_INCLUDED

enum state_t{
    MISSED = -1,
    UNKNOWN = 0,
    HIT = 1
};

class Position{
    state_t state;
public:
    char x;
    int y;

    Position(char x, int y) : x(x), y(y){};
};

class Board{
    int numberOfShips;

public:
    getShipsNumber(){
        return numberOfShips;
    };
};


#endif // BOARD_H_INCLUDED
