#ifndef SPACE_H
#define SPACE_H
#include "ship.h"

class Space{
    bool attacked, occupied;
    string shipContainer;

    public:
        Space();
        Space(bool, bool, string);
        Space(const Space&);

        void setAttacked(bool);
        void setOccupied(bool);
        void setContainer(string);

        bool getAttacked();
        bool getOccupied();
        string getContainer();

        void operator +(Ship);
        friend ostream& operator <<(ostream&, Space);
};

#endif