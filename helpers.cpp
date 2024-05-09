#include "helpers.h"

void startMenu(Player* plyr){
    system("clear");
    cout << "=============================" << endl;
    cout << "ENSURE TERMINAL IS FULLSCREEN" << endl;
    cout << "=============================" << endl << endl;
    cout << "Enter a player name (one word): "; 
    plyr->setPlayerName(getInput<string>());
    system("clear");
}

void printBoards(Player p, Enemy e){
    //system("clear");
    cout << p;
    cout << endl << "================================" << endl << endl;
    cout << e << endl;
}

bool gameOn(Player plyr, Enemy enmy){
    if(plyr.getShipsAlive() > 0 && enmy.getShipsAlive() > 0){
        return true;
    }
    return false;
}

void placeShips(Player* player, Enemy* enemy){
    Location placement;
    char d;
    
    // places player ships and enemy at same time
    for(int i = 0; i < 5; i++){
        system("clear");
        cout <<"= = = PLACE YOUR SHIPS = = =" << endl << endl;
        cout << *player;
        if(i == 0){
            cout << endl <<"= = = Place the Carrier (size 5) = = =" << endl << endl;
            
            // player carrier
            do{
                placement = setPlayerShipPosition(player);
            
                cout << "2) Give a direction" << endl;
                d = getPlayerDirection(5, player, placement);
                if(d == 'F'){
                    cout << "NO POSSIBLE DIRECTIONS AT THIS LOCATION" << endl;
                }
            }while(d == 'F');
            
            player->setShipAt(i, Ship(placement, d, "Carrier", 5, 5));
            placeAShip(player->getShipAt(i), player);

            // enemy carrier
            do{
                placement = setEnemyShipPosition(enemy);
                d = getEnemyDirection(5, enemy, placement);
            }while(d == 'F');

            enemy->setShipAt(i, Ship(placement, d, "Carrier", 5, 5));
            placeAShip(enemy->getShipAt(i), enemy);
        }else if (i == 1){
            cout << endl << "= = = Place the Battleship (size 4) = = =" << endl;

            // player battleship
            do{
                placement = setPlayerShipPosition(player);
            
                cout << "2) Give a direction" << endl;
                d = getPlayerDirection(4, player, placement);
                if(d == 'F'){
                    cout << "NO POSSIBLE DIRECTIONS AT THIS LOCATION" << endl;
                }
            }while(d == 'F');
           
            player->setShipAt(i, Ship(placement, d, "Battleship", 4, 4));
            placeAShip(player->getShipAt(i), player);

            // enemy battleship
            do{
                placement = setEnemyShipPosition(enemy);
                d = getEnemyDirection(4, enemy, placement);
            }while(d == 'F');

            enemy->setShipAt(i, Ship(placement, d, "Battleship", 4, 4));
            placeAShip(enemy->getShipAt(i), enemy);
        }else if (i == 2){
            cout << endl << "= = = Place the Destroyer (size 3) = = =" << endl;

            // player destroyer
            do{
                placement = setPlayerShipPosition(player);
            
                cout << "2) Give a direction" << endl;
                d = getPlayerDirection(3, player, placement);
                if(d == 'F'){
                    cout << "NO POSSIBLE DIRECTIONS AT THIS LOCATION" << endl;
                }
            }while(d == 'F');
            
            player->setShipAt(i, Ship(placement, d, "Destroyer", 3, 3));
            placeAShip(player->getShipAt(i), player);

            //enemy destroyer
            do{
                placement = setEnemyShipPosition(enemy);
                d = getEnemyDirection(3, enemy, placement);
            }while(d == 'F');

            enemy->setShipAt(i, Ship(placement, d, "Destroyer", 3, 3));
            placeAShip(enemy->getShipAt(i), enemy);
        }else if (i == 3){
            cout << endl << "= = = Place the Submarine (size 3) = = =" << endl;
            
            // player submarine
            do{
                placement = setPlayerShipPosition(player);
            
                cout << "2) Give a direction" << endl;
                d = getPlayerDirection(3, player, placement);
                if(d == 'F'){
                    cout << "NO POSSIBLE DIRECTIONS AT THIS LOCATION" << endl;
                }
            }while(d == 'F');
            
            player->setShipAt(i, Ship(placement, d, "Submarine", 3, 3));
            placeAShip(player->getShipAt(i), player);

            // enemy submarine
            do{
                placement = setEnemyShipPosition(enemy);
                d = getEnemyDirection(3, enemy, placement);
            }while(d == 'F');

            enemy->setShipAt(i, Ship(placement, d, "Submarine", 3, 3));
            placeAShip(enemy->getShipAt(i), enemy);
        }else if (i == 4){
            cout << endl << "= = = Place the Patrol Boat (size 2) = = =" << endl;
            

            // player patrol boat
            do{
                placement = setPlayerShipPosition(player);
            
                cout << "2) Give a direction" << endl;
                d = getPlayerDirection(2, player, placement);
                if(d == 'F'){
                    cout << "NO POSSIBLE DIRECTIONS AT THIS LOCATION" << endl;
                }
            }while(d == 'F');
            
            player->setShipAt(i, Ship(placement, d, "Patrol Boat", 2, 2));
            placeAShip(player->getShipAt(i), player);

            // enemy patrol boat
            do{
                placement = setEnemyShipPosition(enemy);
                d = getEnemyDirection(2, enemy, placement);
            }while(d == 'F');

            enemy->setShipAt(i, Ship(placement, d, "Patrol Boat", 2, 2));
            placeAShip(enemy->getShipAt(i), enemy);
        }
    }
}

Location setPlayerShipPosition(Player* plyr){
    Location loc;
    do{
        cout << "1) Give a starting location" << endl;
        loc = playerAttackLoc();

        if(plyr->getSpaceAt(loc.getYPos() - 'a', loc.getXPos()).getOccupied() == true){
            cout << "NOT A VALID START POSITION" << endl;
        }
    }while(plyr->getSpaceAt(loc.getYPos() - 'a', loc.getXPos()).getOccupied() == true);
    return loc;
}

Location setEnemyShipPosition(Enemy* enmy){
    Location loc;
    do{
        loc = enemyAttackLoc();
    }while(enmy->getSpaceAt(loc.getYPos() - 'a', loc.getXPos()).getOccupied() == true);
    return loc;
}

char getPlayerDirection(int length, Player* plyr, Location loc){
    int s = plyr->getBoardSize(), yConvert = loc.getYPos() - 'a', choiceCount = 0;
    char choice;
    bool up = false, down = false, left = false, right = false, exit;
    length--; //fixing for array index

    if(yConvert - length >= 0){ //top board edge check
        up = true;
        
        for(int i = 0; i <= length; i++){ //checks for other ships above
            if(plyr->getSpaceAt(yConvert - i, loc.getXPos()).getOccupied() == true){
                up = false;
                break;
            }
        }

        if(up){
            choiceCount++;
            cout << choiceCount << ". Up (U)" << endl;
        }
    }
    if(yConvert + length < s){ //bottom board edge check
        down = true;
        
        for(int i = 0; i <= length; i++){ //checks for other ships below
            if(plyr->getSpaceAt(yConvert + i, loc.getXPos()).getOccupied() == true){
                down = false;
                break;
            }
        }

        if(down){
            choiceCount++;
            cout << choiceCount << ". Down (D)" << endl;
        }
    }
    if(loc.getXPos() - length >= 0){ //left board edge check
        left = true;
        
        for(int i = 0; i <= length; i++){ //checks for other ships to the left
            if(plyr->getSpaceAt(yConvert, loc.getXPos() - i).getOccupied() == true){
                left = false;
                break;
            }
        }

        if(left){
            choiceCount++;
            cout << choiceCount << ". Left (L)" << endl;
        }
    }
    if(loc.getXPos() + length < s){ //right board edge check
        right = true;
        
        for(int i = 0; i <= length; i++){ //checks for other ships to the right
            if(plyr->getSpaceAt(yConvert, loc.getXPos() + i).getOccupied() == true){
                right = false;
                break;
            }
        }

        if(right){
            choiceCount++;
            cout << choiceCount << ". Right (R)" << endl;
        }
    }

    if(choiceCount == 0){
        return 'F';
    }

    exit = false;
    do{
        cout << "Pick a character for the direction you want (Upper Case ONLY): ";
        choice = getInput<char>();
        switch(choice){
            case 'U':
                if(up){
                    exit = true;
                }
                break;
            case 'D':
                if(down){
                    exit = true;
                }
                break;
            case 'L':
                if(left){
                    exit = true;
                }
                break;
            case 'R':
                if(right){
                    exit = true;
                }
                break;
            default:
                break;
        }

    }while(exit == false);
    cout << endl << endl << "THINKING..." << endl;
    return choice;
}

char getEnemyDirection(int length, Enemy* enmy, Location loc){
    int s = enmy->getBoardSize(), yConvert = loc.getYPos() - 'a', choiceCount = 0, num;
    char choice;
    bool up = false, down = false, left = false, right = false, exit;
    length--; //fixing for array index
    srand (time(NULL));

    if(yConvert - length >= 0){ //top board edge check
        up = true;
        
        for(int i = 0; i <= length; i++){ //checks for other ships above
            if(enmy->getSpaceAt(yConvert - i, loc.getXPos()).getOccupied() == true){
                up = false;
                break;
            }
        }

        if(up){
            choiceCount++;
        }
    }
    if(yConvert + length < s){ //bottom board edge check
        down = true;
        
        for(int i = 0; i <= length; i++){ //checks for other ships below
            if(enmy->getSpaceAt(yConvert + i, loc.getXPos()).getOccupied() == true){
                down = false;
                break;
            }
        }

        if(down){
            choiceCount++;
        }
    }
    if(loc.getXPos() - length >= 0){ //left board edge check
        left = true;
        
        for(int i = 0; i <= length; i++){ //checks for other ships to the left
            if(enmy->getSpaceAt(yConvert, loc.getXPos() - i).getOccupied() == true){
                left = false;
                break;
            }
        }

        if(left){
            choiceCount++;
        }
    }
    if(loc.getXPos() + length < s){ //right board edge check
        right = true;
        
        for(int i = 0; i <= length; i++){ //checks for other ships to the right
            if(enmy->getSpaceAt(yConvert, loc.getXPos() + i).getOccupied() == true){
                right = false;
                break;
            }
        }

        if(right){
            choiceCount++;
        }
    }

    if(choiceCount == 0){
        return 'F';
    }

    exit = false;
    do{
        num = rand() % choiceCount + 1;
        //cout << "Enemy chose: " << num << endl;
        switch(num){
            case 1:
                if(up){
                    choice = 'U';
                    exit = true;
                }
                break;
            case 2:
                if(down){
                    choice = 'D';
                    exit = true;
                }
                break;
            case 3:
                if(left){
                    choice = 'L';
                    exit = true;
                }
                break;
            case 4:
                if(right){
                    choice = 'R';
                    exit = true;
                }
                break;
            default:
                cout << "Enemy had a stroke" << endl;
                break;
        }
    }while(exit == false);
    return choice;
}

void placeAShip(Ship shp, Board* brb){
    int yConvert = shp.getLocation().getYPos() - 'a', x = shp.getLocation().getXPos();
    //cout << "starts at: " << shp.getLocation() << ". Has rotation of: " << shp.getDir() << endl; //Debug line
    if(shp.getDir() == 'U'){
        for(int i = 0; i < shp.getNumParts(); i++){
            Space tempS = brb->getSpaceAt(yConvert - i, x);
            tempS.setOccupied(true);
            //tempS.setContainer(shp.getName());
            tempS + shp;
            //cout << "Temp now has: " << tempS.getContainer() << endl;
            brb->setSpaceAt(yConvert - i, x, tempS);
        }
    } else if(shp.getDir() == 'D'){
        for(int i = 0; i < shp.getNumParts(); i++){
            Space tempS = brb->getSpaceAt(yConvert + i, x);
            tempS.setOccupied(true);
            //tempS.setContainer(shp.getName());
            tempS + shp;
            //cout << "Temp now has: " << tempS.getContainer() << endl;
            brb->setSpaceAt(yConvert + i, x, tempS);
        }
    } else if(shp.getDir() == 'R'){
        for(int i = 0; i < shp.getNumParts(); i++){
            Space tempS = brb->getSpaceAt(yConvert, x + i);
            tempS.setOccupied(true);
            //tempS.setContainer(shp.getName());
            tempS + shp;
            //cout << "Temp now has: " << tempS.getContainer() << endl;
            brb->setSpaceAt(yConvert, x + i, tempS);
        }
    } else if(shp.getDir() == 'L'){
        for(int i = 0; i < shp.getNumParts(); i++){
            Space tempS = brb->getSpaceAt(yConvert, x - i);
            tempS.setOccupied(true);
            //tempS.setContainer(shp.getName());
            tempS + shp;
            //cout << "Temp now has: " << tempS.getContainer() << endl;
            brb->setSpaceAt(yConvert, x - i, tempS);
        }
    }
}

int findShipFromAtLoc(Board* brd, Location atk){
    char d;
    int yConvert = atk.getYPos() - 'a';
    Location loc;
    Space check = brd->getSpaceAt(yConvert, atk.getXPos());
    for(int i = 0; i < 5; i++){
        if(brd->getShipAt(i).getName() == check.getContainer()){
            return i;
        }
    }
    
    return 0; // Mainly geting rid of warning, assumtion is that this function is used only on an occupied space
}

Location playerTurn(Enemy* enmy){
    bool exit = false;
    cout << "Make an attack: " << endl;
    Location atk;
    do{
        atk = playerAttackLoc();
        int yConvert = atk.getYPos() - 'a';
        if((atk.getXPos() >= 0 && atk.getXPos() < enmy->getBoardSize()) && (yConvert >= 0 && yConvert < enmy->getBoardSize())){
            Space tempS = enmy->getSpaceAt(yConvert, atk.getXPos());
            if(tempS.getAttacked() == false){
                tempS.setAttacked(true);
                enmy->setSpaceAt(yConvert, atk.getXPos(), tempS);
                exit = true;
                if(tempS.getOccupied() == true){
                    int index = findShipFromAtLoc(enmy, atk);
                    Ship tempShp = enmy->getShipAt(index);
                    tempShp.setHealth(tempShp.getHealth() - 1);
                    enmy->setShipAt(index, tempShp);

                    if(tempShp.getHealth() <= 0){
                        enmy->setShipAlive(enmy->getShipsAlive() - 1);
                    }
                }
            }else{
                cout << atk << " was already bombed. Please choose a new space. " << endl << endl;
            }
        }else{
            cout << atk << " was is not on the board. Please choose a new space. " << endl << endl;
        }
    }while(exit == false);
    return atk;
}

void enemyTurn(Player* plyr, Enemy* enmy, Location prevAtk){
    bool exit = false;
    do{
        Location atk = enemyAttackLoc();
        int yConvert = atk.getYPos() - 'a';
        Space tempS = plyr->getSpaceAt(yConvert, atk.getXPos());
        if(plyr->getSpaceAt(yConvert, atk.getXPos()).getAttacked() == false){
            tempS.setAttacked(true);
            plyr->setSpaceAt(yConvert, atk.getXPos(), tempS);
            exit = true;
            system("clear"); //clears the "enemy is making move text"
            if(prevAtk.getYPos() != 'z'){ //'z' is default for location, means it is enemy going first
                if(enmy->getSpaceAt(prevAtk.getYPos() - 'a', prevAtk.getXPos()).getOccupied() == true){    
                    cout << "Enemy: " << prevAtk << " is a hit.";
                    int index = findShipFromAtLoc(enmy, prevAtk);
                    if(enmy->getShipAt(index).getHealth() <= 0){
                        cout << " You sunk my " << enmy->getShipAt(index) << "!" << endl;
                    }else{
                        cout << endl;
                    }
                }else{
                    cout << "Enemy: " << prevAtk << " is a miss." << endl;
                }
            }else{
                cout << "Computer goes first" << endl << endl; //needs to be here becuase of placement of 'system("clear")'
            }
            cout << "Enemy: I will bomb " << atk << endl;
            cout << "Player: ";
            if(tempS.getOccupied() == true){
                int index = findShipFromAtLoc(plyr, atk);
                Ship tempShp = plyr->getShipAt(index);
                tempShp.setHealth(tempShp.getHealth() - 1);
                plyr->setShipAt(index, tempShp);
                if(tempShp.getHealth() <= 0){
                    cout << "You hit and sunk my " << tempShp << "!" << endl;
                }else{
                    cout << atk << " is a hit." << endl << endl;
                }
                if(tempShp.getHealth() <= 0){
                    plyr->setShipAlive(plyr->getShipsAlive() - 1);
                }
            }else{
                cout << atk << " is a miss." << endl << endl;
            }
        }
    }while(exit == false);
}

Location playerAttackLoc(){
    int tempX;
    char tempY;
    
    do{
        cout << "Column location (int): ";
        tempX = getInput<int>();
        if(tempX < 0 || tempX > 9){
            cout << "NOT A VALID CHOICE" << endl;
        }
    }while(tempX < 0 || tempX > 9);
    
    do{
        cout << "Row location (char): ";
        tempY = getInput<char>();
        if(tempY < 'a' || tempY > 'j'){
            cout << "NOT A VALID CHOICE" << endl;
        }
    }while(tempY < 'a' || tempY > 'j');

    Location temp(tempX, tempY);
    return temp;
}

Location enemyAttackLoc(){
    srand (time(NULL));

    int tempX;
    char tempY;
    tempX = rand() % 10;
    tempY = rand() % 10;

    tempY += 'a';

    Location temp(tempX, tempY);
    return temp;
}

template <typename T>
T getInput(){
    T temp;
    cin >> temp;
    return temp;
}

ostream& operator <<(ostream& out, Player plyr){
    out << plyr.playerName << "'s Board:" << endl;
    out << "   0  1  2  3  4  5  6  7  8  9" << endl;
    for(int i = 0; i < plyr.sizeOfBoard; i++){
        char temp = 'a' + i;
        out << temp << " ";
        for(int j = 0; j < plyr.sizeOfBoard; j++){
            if(plyr.spaces[i][j].getOccupied() == false){
                out << "[" << plyr.spaces[i][j] << "]";
            }else{
                if(plyr.spaces[i][j].getAttacked() == true){
                    out << "[x]";
                }else{
                    out << "[#]";
                }
            }
        }
        out << endl;
    }
    out << endl;
    plyr.displayProgress();
    return out;
}

ostream& operator <<(ostream& out, Enemy enmy){
    out <<"Enemy Board:" << endl;
    out << "   0  1  2  3  4  5  6  7  8  9" << endl;
    for(int i = 0; i < enmy.sizeOfBoard; i++){
        char temp = 'a' + i;
        out << temp << " ";
        for(int j = 0; j < enmy.sizeOfBoard; j++){
            // if(enmy.spaces[i][j].getOccupied() == false){
            //     out << "[" << enmy.spaces[i][j] << "]";
            // }else{
            //     if(enmy.spaces[i][j].getAttacked() == true){
            //         out << "[x]";
            //     }else{
            //         out << "[#]";
            //     }
            // }
            
            if(enmy.spaces[i][j].getOccupied() == true && enmy.spaces[i][j].getAttacked() == true){
                out << "[X]";
            }else{
                out << "[" << enmy.spaces[i][j] << "]";
            }
        }
        out << endl;
    }
    out << endl;
    enmy.displayProgress();
    return out;
}

ostream& operator <<(ostream& out, Space spc){
    if(spc.attacked == true){
        out << "~";
    }else{
        out << " ";
    }
    return out;
}

ostream& operator <<(ostream& out, Ship shp){
    out << shp.name;
    return out;
}

ostream& operator <<(ostream& out, Location l){
    out << "(" << l.xPos << "," << l.yPos << ")";
    return out;
}