#include <iostream>
#include "ship.h"
#include "board.h"



int main()
{
    int boardSize = 10;
    std::cout << "Hello world!" << std::endl;
    Board playerBoard(boardSize);
    playerBoard.draw();

    return 0;
}
