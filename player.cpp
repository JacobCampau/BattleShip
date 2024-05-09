#include "player.h"

Player::Player():Board(){
    playerName = "John Smith";
}

Player::Player(string nm, int s, Space** spc, int a, Ship* shp):Board(s, spc, a, shp){
    playerName = nm;
}

Player::Player(const Player& rhs):Board(rhs){
    playerName = rhs.playerName;
}

void Player::setPlayerName(string nm){
    playerName = nm;
}

string Player::getPlayerName(){
    return playerName;
}

void Player::displayProgress(){
    int found = 0;
    for(int i = 0; i < 5; i++){
        //cout << "HEALTH OF " << ships[i] << ". Being compared to: " << ships[i].getNumParts() << endl;
        if(ships[i].getHealth() < ships[i].getNumParts()){
            found++;
        }
    }

    cout << "The Enemy has sunk " << 5 - shipsAlive << " ship(s) and has found " << found << " ship(s)." << endl;
}