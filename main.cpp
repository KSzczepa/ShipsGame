#include <iostream>
#include "include/ship.h"
#include "include/board.h"



int main()
{
    int boardSize = 10;
    int numberOfShips = 0;

    std::cout << "Hello world!" << std::endl;
    Board playerBoard(boardSize);
    playerBoard.draw();

    while (numberOfShips <= 10)
    {
        playerBoard.addShip();
        playerBoard.draw();
        numberOfShips = playerBoard.getNumberOfShips();
    }

    return 0;
}
