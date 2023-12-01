#include "ship.h"
#include <iostream>

int Ship::playerShips = 0;
int Ship::enemyShips = 0;

Ship::Ship(ship_types_t t, ship_direction_t dir, startPoint_t sp, ship_property_t p = PLAYER) : type(t), direction(dir), sP(sp), property(p){
    if (p == PLAYER)
        playerShips++;
    else if (p == ENEMY)
        enemyShips++;
};

Ship::~Ship(){
    std::cout << "The ship of type " << type << "has been destroyed!" << std::endl;
};