#ifndef POSITION_H
#define POSITION_H

#include "state.h"
#include "ship.h"

class Position{
    state_t state;

public:
    char x;
    int y;

    // Position();
    // ~Position();
    Position(char x, int y) : x(x), y(y){
        state = UNKNOWN;
    };
    Position(char x, int y, state_t s) : Position(x, y){
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

////////////////////////////////////////////////////////////////
// Position::Position()
// {
//    //ctor
// };

// Position::~Position()
// {
//    //dtor
// };

// Position::Position(char x, int y) : x(x), y(y){
//        state = UNKNOWN;
//    };

// Position::Position(char x, int y, state_t s) : Position(x, y) {
//        state = s;
//    };

#endif // POSITION_H
