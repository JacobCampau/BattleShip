#ifndef HELPERS_H
#define HELPERS_H
#include "player.h"

void startMenu(Player*);
void printBoards(Player, Enemy);
void placeShips(Player*, Enemy*);
Location setPlayerShipPosition(Player*);
Location setEnemyShipPosition(Enemy*);
char getPlayerDirection(int, Player*, Location);
char getEnemyDirection(int, Enemy*, Location);
void placeAShip(Ship, Board*);
int findShipFromAtLoc(Board*, Location);
Location playerTurn(Enemy*);
void enemyTurn(Player*, Enemy*, Location);
bool gameOn(Player, Enemy);
Location playerAttackLoc();
Location enemyAttackLoc();

template <typename T>
T getInput();

#endif 