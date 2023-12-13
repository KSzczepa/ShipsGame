#ifndef SHIP_H_INCLUDED
#define SHIP_H_INCLUDED

#include <iostream>
#include "position.h"

enum ship_direction_t{
    HORIZONTAL = 0,
    VERTICAL = 1
};

enum ship_property_t{
    PLAYER = 0,
    ENEMY = 1
};

enum ship_types_t{
    X1 = 1,
    X2 = 2,
    X3 = 3,
    X4 = 4,
};

struct startPoint_t{
    char x;
    int y;
};

class Ship {
    static int playerShips;
    static int enemyShips;
    ship_property_t property;
    ship_types_t type;
    ship_direction_t direction;
    startPoint_t sP;

    public: 
    Ship(ship_types_t t, ship_direction_t dir, startPoint_t sp, ship_property_t p = PLAYER);

    ~Ship();

    void validatePosition(Position p);

    startPoint_t nextPosition(startPoint_t point);

    ship_types_t getType(void);

    ship_direction_t getDirection(void);

    startPoint_t getStartPoint(void);
};


//////////////////////////////////////////////////////////
int Ship::playerShips = 0;
int Ship::enemyShips = 0;

Ship::Ship(ship_types_t t, ship_direction_t dir, startPoint_t sp, ship_property_t p) : type(t), direction(dir), sP(sp), property(p){
    if (p == PLAYER)
        playerShips++;
    else if (p == ENEMY)
        enemyShips++;
};

void Ship::validatePosition(Position p) {
    for (int i=0; i<type; i++) {

    }
};

startPoint_t Ship::nextPosition(startPoint_t point) {
    if (direction == HORIZONTAL) {
        point.y += 1;
    }
    else if (direction == VERTICAL) {
        point.x += 1;
    }
    return point;
};

ship_types_t Ship::getType(void) {
    return type;
};

ship_direction_t Ship::getDirection(void){
    return direction;
};

Ship::~Ship(){
    std::cout << "The ship of type " << type << "has been destroyed!" << std::endl;
};

#endif //SHIP_H_INCLUDED