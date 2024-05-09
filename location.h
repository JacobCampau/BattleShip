#ifndef LOCATION_H
#define LOCATION_H
#include <iostream>
#include <time.h>
#include <stdlib.h>
using namespace std;

class Location{
    int xPos;
    char yPos;

    public:
        Location();
        Location(int, char);
        Location(const Location& rhs);

        void setXPos(int);
        void setYPos(char);

        int getXPos();
        char getYPos();

        bool operator ==(Location& loc) const;
        friend ostream& operator <<(ostream&, Location);
};

#endif