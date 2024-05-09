#ifndef BOARD_H
#define BOARD_H
#include "space.h"

class Board{
    protected:
        int sizeOfBoard;
        Space** spaces;
        int shipsAlive;
        Ship* ships;

    public:
        Board();
        Board(int, Space**, int, Ship*);
        Board(const Board&);

        void setBoardSize(int);
        void setSpaceAt(int, int, Space);
        void setShipAlive(int);
        void setShipAt(int, Ship);

        int getBoardSize();
        Space getSpaceAt(int, int);
        int getShipsAlive();
        Ship getShipAt(int);

        ~Board();
        Board& operator =(const Board&);

        virtual void displayProgress() = 0;
};

#endif