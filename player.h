#ifndef PLAYER_H
#define PLAYER_H
#include "enemy.h"

class Player: public Board{
    string playerName;

    public:
        Player();
        Player(string, int, Space**, int, Ship*);
        Player(const Player&);

        void setPlayerName(string);

        string getPlayerName();

        void displayProgress();

        friend ostream& operator <<(ostream&, Player);
};

#endif