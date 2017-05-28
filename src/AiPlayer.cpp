#include "AiPlayer.h"
#include <cstdlib>
#include "DefaultTank.h"
#include "LaserTank.h"
#include "ArmouredTank.h"
#include <stdlib.h>
#include <time.h>

AiPlayer::AiPlayer(int credits, std::vector<WarObject *> generalWarObjectList, UiHandler * uiHandler) : Player (credits, generalWarObjectList, uiHandler)
{
    srand(time(NULL));
}

void AiPlayer::init(){
    if(debug) uiHandler->printMessage("Initializing AI Player...");
    while(credits > 0){

        int tankNumber;
        do{
            tankNumber = getRandomInt(1, generalWarObjectList.size());
        }while(credits < generalWarObjectList[tankNumber-1]->getCreditCost());

        credits -= generalWarObjectList[tankNumber-1]->getCreditCost();

        WarObject * tankPointer;
        switch(tankNumber){
            case 1: tankPointer = new DefaultTank(); break;
            case 2: tankPointer = new LaserTank(); break;
            case 3: tankPointer = new ArmouredTank(); break;
        }

        bool alright = false;
        Location * location;
        while(!alright){
            tankPointer->setLocation(getRandomInt(0, (field->getRowSize() - tankPointer->getRowSize())-1), getRandomInt(0, (field->getColumnSize() - tankPointer->getColumnSize())-1), getRandomInt(0,1));
            if(!detector->checkObjectCollision(warObjectList,tankPointer)) alright = true;
        }

        delete location;

        warObjectList.push_back(tankPointer);
    }
    if(debug){
        uiHandler->printMessage("Complete!");
        uiHandler->printWarObjects(warObjectList);

        field->reset();
        field->drawWarObjects(warObjectList);
        uiHandler->printMessage(field->generateField());
        system("pause");
        system("cls");
    }
}

void AiPlayer::yourTurn(){
    uiHandler->printMessage("The AI player is firing...");
    int tankNumber = getRandomInt(1, warObjectList.size());
    Location * location;
    do{
         location = new Location(getRandomInt(0, field->getColumnSize()-1), getRandomInt(0, field->getRowSize()-1));
    }while(checkForReusedShootingLocation(location));

    addFiredBullet(new Bullet(location->getXLocation(), location->getYLocation(), warObjectList[tankNumber-1]->getDamage()));
}

void AiPlayer::reportBullets(std::vector<Bullet *> bullets){
    incommingBullet(bullets.back());
    system("pause");
    system("cls");
}



AiPlayer::getRandomInt(int minim, int maxim){
    return (rand() % (maxim-(minim-1))) + minim;
}


