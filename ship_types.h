/*Basic defines*/

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


class Ship {
    static int playerShips;
    static int enemyShips;
    ship_property_t property;
    ship_types_t type;
    ship_direction_t direction;


    Ship(ship_property_t p, ship_types_t t) : property(p), type(t) {
        if (p == PLAYER)
            playerShips++;
        else if (p == ENEMY)
            enemyShips++;
    };
};


int Ship::playerShips = 0;
int Ship::enemyShips = 0;
