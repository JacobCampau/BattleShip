#include "board.h"

Board::Board(){
    sizeOfBoard = 10;
    spaces = new Space*[sizeOfBoard];
    for(int i = 0; i < sizeOfBoard; i++){
        spaces[i] = new Space[sizeOfBoard];
    }
    shipsAlive = 5;
    ships = new Ship[shipsAlive];
}

Board::Board(int s, Space** spc, int a, Ship* shp){
    sizeOfBoard = s;
    spaces = new Space*[sizeOfBoard];
    for(int i = 0; i < sizeOfBoard; i++){
        spaces[i] = new Space[sizeOfBoard];
    }
    for(int i = 0; i < sizeOfBoard; i++){
        for(int j = 0; j < sizeOfBoard; j++){
            spaces[i][j] = spc[i][j];
        }
    }
    shipsAlive = a;
    ships = new Ship[shipsAlive];
    for(int i = 0; i < shipsAlive; i++){
        ships[i] = shp[i];
    }
}

Board::Board(const Board& rhs){
    sizeOfBoard = rhs.sizeOfBoard;
    spaces = new Space*[sizeOfBoard];
    for(int i = 0; i < sizeOfBoard; i++){
        spaces[i] = new Space[sizeOfBoard];
    }
    for(int i = 0; i < sizeOfBoard; i++){
        for(int j = 0; j < sizeOfBoard; j++){
            spaces[i][j] = rhs.spaces[i][j];
        }
    }
    shipsAlive = rhs.shipsAlive;
    ships = new Ship[shipsAlive];
    for(int i = 0; i < shipsAlive; i++){
        ships[i] = rhs.ships[i];
    }
}

void Board::setBoardSize(int s){
    sizeOfBoard = s;
}

void Board::setSpaceAt(int r, int c, Space s){
    spaces[r][c] = s;
}

void Board::setShipAlive(int a){
    shipsAlive = a; 
}

void Board::setShipAt(int i, Ship s){
    ships[i] = s;
}

int Board::getBoardSize(){
    return sizeOfBoard;
}

Space Board::getSpaceAt(int r, int c){
    return spaces[r][c];
}

int Board::getShipsAlive(){
    return shipsAlive;
}

Ship Board::getShipAt(int i){
    return ships[i];
}

Board::~Board(){
    for(int i = 0; i < sizeOfBoard; i++){
        delete [] spaces[i];
    }
    delete [] ships;
}

Board& Board::operator =(const Board& rhs){
    sizeOfBoard = rhs.sizeOfBoard;
    spaces = new Space*[sizeOfBoard];
    for(int i = 0; i < sizeOfBoard; i++){
        spaces[i] = new Space[sizeOfBoard];
    }
    for(int i = 0; i < sizeOfBoard; i++){
        for(int j = 0; j < sizeOfBoard; j++){
            spaces[i][j] = rhs.spaces[i][j];
        }
    }
    shipsAlive = rhs.shipsAlive;
    ships = new Ship[shipsAlive];
    for(int i = 0; i < shipsAlive; i++){
        ships[i] = rhs.ships[i];
    }
    return *this;
}