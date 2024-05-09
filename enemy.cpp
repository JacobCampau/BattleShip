#include "enemy.h"

Enemy::Enemy():Board(){
}

Enemy::Enemy(int s, Space** spc, int a, Ship* shp):Board(s, spc, a, shp){
}

Enemy::Enemy(const Enemy& rhs):Board(rhs){
}

void Enemy::displayProgress(){
    cout << "You have sunk " << 5 - shipsAlive << " ship(s)." << endl;
}