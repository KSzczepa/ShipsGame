#ifndef SHIP_H_INCLUDED
#define SHIP_H_INCLUDED

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
    X5 = 5
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

    Ship(ship_types_t t, ship_direction_t dir, startPoint_t sp, ship_property_t p = PLAYER);

    ~Ship();
};


// int Ship::playerShips = 0;
// int Ship::enemyShips = 0;

#endif //SHIP_H_INCLUDED