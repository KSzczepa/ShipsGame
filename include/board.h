#ifndef BOARD_H_INCLUDED
#define BOARD_H_INCLUDED

#include <vector>
#include "position.h"
#include "state.h"
#include "ship.h"


class Board{
    int numberOfShips;
    const int minSize = 5;
    const int maxSize = 10;
    Position* pStartPos;
    std::vector<Position> positionsContainer; //container

public:
    int size;

    Board(int size);

    int getShipsNumber();

    void Board::createShip(ship_types_t type, ship_direction_t dir, startPoint_t sp);

    void addShip();

    void addShip(ship_types_t type, ship_direction_t dir, char startPosX, int startPosY);

    Position* findPosition(char x, int y);

    void draw(void);
};


#endif // BOARD_H_INCLUDED
