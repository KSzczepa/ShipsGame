#ifndef BOARD_H_INCLUDED
#define BOARD_H_INCLUDED

#include <vector>
#include "position.h"
#include "state.h"
#include "ship.h"
#include <iostream>
#include <sstream>
#include <string>
#include "lines.h"
#include <stdlib.h>

#define OK 0
#define NOK 1

#define MAX_BOARD_LENGTH 10


class Board{
    int numberOfShips;
    const int minSize = 5;
    const int maxSize = 10;
    Position* pStartPos;
    Position* pCurrentPos;
    std::vector<Position> positionsContainer; //container
    std::vector<Ship> activeShips;

public:
    int size;

    Board(int size);

    int getShipsNumber();

    Ship* createShip(ship_types_t type, ship_direction_t dir, startPoint_t sp);

    void addShip();

    void addShip(ship_types_t type, ship_direction_t dir, char startPosX, int startPosY);

    Position* findPosition(char x, int y);

    void draw(void);

    int validate(Ship* ship2Validation, startPoint_t sp, int length);

    int getNumberOfShips(void);

    void Board::setOccupiedPoles(Ship &currentShip, startPoint_t sPoint);
};


/////////////////////////////////////////////////
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
    // Position* pCurrentPos;
    // for (auto pos : positionsContainer) {
    //     if (pos.x == x && pos.y == y) {
    //         pCurrentPos = &pos;
    //         return &pos;
    //     }
    // }
    for (int idx=0; idx<positionsContainer.size(); idx++) {
        if (positionsContainer[idx].x == x && positionsContainer[idx].y == y) {
            pCurrentPos = &positionsContainer[idx];
            return &positionsContainer[idx];
        }
    }

    return pCurrentPos;
};

void Board::addShip(){
    ship_types_t shipType;
    ship_direction_t shipDir;
    startPoint_t sp;
    Ship* pCurrentShip;
    int validationState = OK;
    
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
    shipDir = dir == 'h' ? HORIZONTAL : VERTICAL;

    std::cout << "Choose start point. Type letter and number." << std::endl;
    std::string spos;
    // std::getline(std::cin, spos);
    std::cin >> spos;
    std::stringstream ss(spos);
    ss >> sp.x >> sp.y;
    toupper(sp.x);

    pCurrentShip = createShip(shipType, shipDir, sp);
    validationState = validate(pCurrentShip, sp, typeNr);

    if (validationState == OK) {
        setOccupiedPoles(*pCurrentShip, sp);
    }
    else 
    {
        std::cout << "The new ship cannot be on ar directly next to another ship. Choose again" << std::endl;
        pCurrentShip->~Ship();
    }    
};

int Board::validate(Ship* ship2Validation, startPoint_t sp, int length) {
    int state = OK;
    ship_types_t type = ship2Validation->getType();
    ship_direction_t dir = ship2Validation->getDirection();
    int typeNr = static_cast<int>(type);
    if (dir == HORIZONTAL && (typeNr + sp.y > MAX_BOARD_LENGTH + 1))
        state = NOK;
    if (dir == VERTICAL && (typeNr + sp.x > 75) )
        state = NOK;

    if (state == OK) {
        for (int i=0; i<length; i++) {
            findPosition(sp.x, sp.y);
            if (pCurrentPos->getState() == OCCUPIED) {                
                state = NOK;
            }
            else if (pCurrentPos->getState() == UNKNOWN) {
                sp = ship2Validation->nextPosition(sp);
            }
        }
        state = OK;
    }
    else 
        std::cout << "Incorrect data" << std::endl;

    return state;
};

Ship* Board::createShip(ship_types_t type, ship_direction_t dir, startPoint_t sp) {
    ship_property_t p = PLAYER;
    Ship *s = new Ship(type, dir, sp, p);
    return s;
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
        else {
            //if PLAYER or if ENEMY - should be sth different
            //TODO
            if (currState == OCCUPIED)
                std::cout << " H ";
            else
                std::cout << " _ ";
        }


        cp++;
        if (cp%10 == 0) {
            std::cout <<std::endl;
            l++;
        }

    }

    std::cout << std::endl;    
};

int Board::getNumberOfShips(void){
    int length = 0;
    return activeShips.size();
};

void Board::setOccupiedPoles(Ship &currentShip, startPoint_t sp) {
    int typeNr = 0;
    typeNr = static_cast<int>(currentShip.getType());
    ship_direction_t direction;
    direction = currentShip.getDirection();

    for (int i=0; i<typeNr; i++) {
        findPosition(sp.x, sp.y);
        pCurrentPos->setState(OCCUPIED);

        //Set also as occupied poles next to this one
        // if (direction == VERTICAL) {
        //     if (sp.x != 'A' && i == 0) {
        //         (pCurrentPos-10)->setState(OCCUPIED);
        //     }
        //     else if (sp.x != 'J')
        // }
        // else if (direction == HORIZONTAL) {

        // }

        sp = currentShip.nextPosition(sp);
    }
    activeShips.push_back(currentShip);
};


#endif // BOARD_H_INCLUDED
