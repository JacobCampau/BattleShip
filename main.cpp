#include "helpers.h"

int main(){
    Player playerBoard;
    Enemy enemyBoard;
    char replay;
    Location previousAtk;

    srand (time(NULL));

    do{
        int start = rand() % 2;
        startMenu(&playerBoard);
        placeShips(&playerBoard, &enemyBoard);
        system("clear");

        if(start == 1){
            enemyTurn(&playerBoard, &enemyBoard, previousAtk);
        }else{
            cout << playerBoard.getPlayerName() << " goes first" << endl << endl;
        }
        
        do{
            printBoards(playerBoard, enemyBoard);
            previousAtk = playerTurn(&enemyBoard);
            system("clear");
            cout << "ENEMY IS MAKING MOVE..." << endl; //loading "screen" text
            enemyTurn(&playerBoard, &enemyBoard, previousAtk);
        }while(gameOn(playerBoard, enemyBoard) == true);
        
        system("clear");

        printBoards(playerBoard, enemyBoard);
        cout << "= = = = = GAME OVER = = = = =" << endl << "Winner: ";
        if(playerBoard.getShipsAlive() > 0){
            cout << playerBoard.getPlayerName() << endl;
        }else{
            cout << "Computer" << endl;
        }

        cout << endl << "PLAY AGAIN?" << endl;
        do{
            cout << "(Y or N): ";
            replay = getInput<char>();
            if(replay != 'Y' && replay != 'N' && replay != 'y' && replay != 'n'){
                cout << "NOT AN OPTION" << endl;
            }
        }while(replay != 'Y' && replay != 'N' && replay != 'y' && replay != 'n');
    }while(replay != 'n' && replay != 'N');

    cout << endl << "Thanks for playing!!" << endl;
    return 0;
}