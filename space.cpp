#include "space.h"

Space::Space(){
    attacked = false;
    occupied = false;
    shipContainer = "NO SHIP ON SPACE";
}

Space::Space(bool o, bool a, string s){
    occupied = o;
    attacked = a;
    shipContainer = s;
}

Space::Space(const Space& rhs){
    occupied = rhs.occupied;
    attacked = rhs.attacked;
    shipContainer = rhs.shipContainer;
}

void Space::setAttacked(bool a){
    attacked = a;
}

void Space::setOccupied(bool o){
    occupied = o;
}

void Space::setContainer(string s){
    shipContainer = s;
}

bool Space::getAttacked(){
    return attacked;
}

bool Space::getOccupied(){
    return occupied;
}

string Space::getContainer(){
    return shipContainer;
}

void Space::operator +(Ship shp){
    shipContainer = shp.getName();
}