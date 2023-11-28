#ifndef BOARD_H_INCLUDED
#define BOARD_H_INCLUDED

#include <vector>

enum state_t{
    MISSED = -1,
    UNKNOWN = 0,
    HIT = 1
};

class Board;

class Position{
    state_t state;
    // friend Board;
public:
    char x;
    int y;

    Position(char x, int y) : x(x), y(y){
        state = UNKNOWN;
    };
    Position(char x, int y, state_t s) : Position(x, y) {
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
    Position* pStartPos;
    Position* pCurrentPos;
    std::vector<Position> v; //container

public:
    int size;

    Board(int size) : size(size) {
        // pStartBoard = new Position(size*size);
        char startLetter = 'A';
        for (int x=0; x<size; x++) {
            for (int y=0; y<size; y++) {
                Position field(startLetter+1*x, y);
                v.push_back(field);
            }
                //std::cout << v[x].x  << " ";
        }
        pStartPos = &v[0];
        numberOfShips = 0;
    };

    int getShipsNumber(){
        return numberOfShips;
    };

    int addShip() {

    };

    Position findPosition(char x, int y) {

    };

    void draw(void) {
        char let = 'A';
        //Position* pCurrent = pStartPos;

        for (int m=0; m<size; m++) {
            std::cout << " " << m+1 << " ";
        }
        std::cout << std::endl;


            {
        int cp = 0; int l = 65;
                {
                for (auto pos : v) {
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
            }
            std::cout << std::endl;
        }
    };
};


#endif // BOARD_H_INCLUDED
