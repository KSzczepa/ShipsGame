#include "board.h"
#include <iostream>
#include <sstream>
#include <string>
#include "ship.h"

Board::Board(int size) : size(size) {
        char startLetter = 'A';
        for (int x=0; x<size; x++) {
            for (int y=0; y<size; y++) {
                Position field(startLetter+1*x, y);
                positionsContainer.push_back(field);
            }
        }
        pStartPos = &positionsContainer[0];
        numberOfShips = 0;
    };

int Board::getShipsNumber(){
        return numberOfShips;
};

Position* Board::findPosition(char x, int y){
    Position* pCurrentPos;
    for (auto pos : positionsContainer) {
        if (pos.x == x && pos.y == y) {
            pCurrentPos = &pos;
            break;
        }
    }
    return pCurrentPos;
};

void Board::addShip(){
    ship_types_t shipType;
    ship_direction_t shipDir;
    startPoint_t sp;
    
    std::cout << "Choose ship type: " << std::endl;
    for (int i=1; i<=5; i++) {
        std::cout << i << ". X" << i << std::endl;
    }
    int typeNr = 0;
    std::cin >> typeNr;
    shipType = static_cast<ship_types_t>(typeNr);

    std::cout << "Choose direction: " << std::endl;
    std::cout << "h. HORIZONTAL" << std::endl;
    std::cout << "v. VERTICAL" << std::endl;

    char dir;
    std::cin >> dir;
    shipDir = static_cast<ship_direction_t>(dir);

    std::cout << "Choose start point. Type letter and number." << std::endl;
    std::string spos;
    std::getline(std::cin, spos);
    std::stringstream ss(spos);
    ss >> sp.x >> sp.y;

    //TODO validation fcn

    
};

void Board::createShip(ship_types_t type, ship_direction_t dir, startPoint_t sp) {
    ship_property_t p = PLAYER;
    Ship s(type, dir, sp, p);
};

void Board::draw(void) {
    char let = 'A';

    for (int m=0; m<size; m++) {
        std::cout << " " << m+1 << " ";
    }
    std::cout << std::endl;
        
    int cp = 0; int l = 65;
            
    for (auto pos : positionsContainer) {
        if (cp%10 == 0) std::cout << static_cast<char>(l);
        state_t currState = pos.getState();
        if (currState == MISSED)
            std::cout << " O ";
        else if (currState == HIT)
            std::cout << " X ";
        else
            std::cout << " _ ";


        cp++;
        if (cp%10 == 0) {
            std::cout <<std::endl;
            l++;
        }

    }

    std::cout << std::endl;    
};