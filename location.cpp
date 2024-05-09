#include "location.h"

Location::Location(){
    xPos = 0;
    yPos = 'z';
}

Location::Location(int x, char y){
    xPos = x;
    yPos = y;
}

Location::Location(const Location& rhs){
    xPos = rhs.xPos;
    yPos = rhs.yPos;
}

void Location::setXPos(int x){
    xPos = x;
}

void Location::setYPos(char y){
    yPos = y;
}

int Location::getXPos(){
    return xPos;
}

char Location::getYPos(){
    return yPos;
}

bool Location::operator==(Location& loc) const{
    if(loc.xPos == xPos && loc.yPos == yPos){
        return true;
    }else{
        return false;
    }
}