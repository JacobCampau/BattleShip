#ifndef SHIP_H
#define SHIP_H
#include "location.h"

class Ship{
    Location startPos;
    char dir;
    string name;
    int numOfParts, health;

    public:
        Ship();
        Ship(Location, char, string, int, int);
        Ship(const Ship&);

        void setLocation(Location);
        void setDir(char);
        void setName(string);
        void setNumParts(int);
        void setHealth(int);

        Location getLocation();
        char getDir();
        string getName();
        int getNumParts();
        int getHealth();

        friend ostream& operator <<(ostream&, Ship);
};

#endif