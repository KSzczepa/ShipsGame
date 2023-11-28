#ifndef BOARD_H_INCLUDED
#define BOARD_H_INCLUDED

#include <vector>

enum state_t{
    MISSED = -1,
    UNKNOWN = 0,
    HIT = 1
};

class Position{
    state_t state;
    friend Board;
public:
    char x;
    int y;

    Position(char x, int y) : x(x), y(y){
        state = UNKNOWN;
    };
    Position(char x, int y, state_t s) : Position(char x, int y) {
        state = s;
    };

    void setState(state_t newState) {
        if (state != newState) 
            state = newState;
    };

    state_t getState(void) {
        return state;
    };

    Position* givePosition(char letter, int num){
        if (letter == x && num == y)
            return this;
    }
};

class Board{
    int numberOfShips;
    const int minSize = 5;
    const int maxSize = 10;
    // Position* pStartBoard;
    Position* pCurrentPos;
    std::vector<Position> v;

public:
    int size;

    Board(int size) : size(size) {
        // pStartBoard = new Position(size*size);
        char startLetter = 'A';
        for (int x=0; x<size; x++) {
            for (int y=0; i<size; i++) {
                Position field = new Position(startLetter+1*x, y);
            }
        }
        numberOfShips = 0;
    };

    int getShipsNumber(){
        return numberOfShips;
    };

    int addShip() {

    };

    Position findPosition(char x, int y) {

    };
};


#endif // BOARD_H_INCLUDED
