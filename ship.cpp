#include "ship.h"

Ship::Ship(){
    startPos = Location();
    dir = 'U';
    name = "NO NAME ASSIGNED";
    numOfParts = 1;
    health = 1;
}

Ship::Ship(Location s, char d, string n, int num, int h){
    startPos = s;
    dir = d;
    name = n;
    numOfParts = num;
    health = h;
}

Ship::Ship(const Ship& rhs){
    startPos = rhs.startPos;
    dir = rhs.dir;
    name = rhs.name;
    numOfParts = rhs.numOfParts;
    health = rhs.health;
}

void Ship::setLocation(Location loc){
    startPos = loc;
}

void Ship::setDir(char d){
    dir = d;
}

void Ship::setName(string n){
    name = n;
}

void Ship::setNumParts(int num){
    numOfParts = num;
}

void Ship::setHealth(int hp){
    health = hp;
}

Location Ship::getLocation(){
    return startPos;
}

char Ship::getDir(){
    return dir;
}

string Ship::getName(){
    return name;
}

int Ship::getNumParts(){
    return numOfParts;
}

int Ship::getHealth(){
    return health;
}