#ifndef ENEMY_H
#define ENEMY_H
#include "board.h"

class Enemy:public Board{
    public:
        Enemy();
        Enemy(int, Space**, int, Ship*);
        Enemy(const Enemy&);

        void displayProgress();

        friend ostream& operator <<(ostream&, Enemy);
};

#endif