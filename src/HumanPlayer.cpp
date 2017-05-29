#include "HumanPlayer.h"
#include <cstdlib>
#include "DefaultTank.h"
#include "LaserTank.h"
#include "ArmouredTank.h"

HumanPlayer::HumanPlayer(int credits, std::vector<WarObject *> generalWarObjectList, UiHandler * uiHandler) : Player (credits, generalWarObjectList, uiHandler)
{

}

void HumanPlayer::init(){
    uiHandler->printStartScreen();
    system("pause");
    system("cls");

    while(credits > 0){
        uiHandler->printMessage("These are all the tanks you can purchase, they have their unique stats.");
        uiHandler->printMessage("Choose wisely!");
        uiHandler->printWarObjects(generalWarObjectList);

        uiHandler->printMessage("Your current arsenal: ");
        uiHandler->printWarObjects(warObjectList);

        uiHandler->printNumber("Credits left: ", credits);

        //Ask what tank the user wants to buy
        int tankNumber;
        do{
            tankNumber = uiHandler->askNumber("What tank do you want to buy?:", 1, generalWarObjectList.size());
        }while(credits < generalWarObjectList[tankNumber-1]->getCreditCost());

        credits -= generalWarObjectList[tankNumber-1]->getCreditCost();

        WarObject * tankPointer;
        switch(tankNumber){
            case 1: tankPointer = new DefaultTank(); break;
            case 2: tankPointer = new LaserTank(); break;
            case 3: tankPointer = new ArmouredTank(); break;
        }

        system("cls");
        uiHandler->printMessage("Place your newly purchased tank. Make sure to not place them outside the area or on other tanks.");
        uiHandler->newLine();

        //Show the field
        field->reset();
        field->drawWarObjects(warObjectList);
        uiHandler->printMessage(field->generateField());

        bool alright = false;
        Location * location;
        while(!alright){
            location = uiHandler->askLocation("Enter the coordinates (eg. C5): ", field->getColumnSize(), field->getRowSize());
            int turned = uiHandler->askNumber("Turn the tank by 90deg?  (1=YES 0=NO): ",0, 1);
            tankPointer->setLocation(location->getYLocation(), location->getXLocation(), turned);
            if(!detector->checkObjectCollision(warObjectList,tankPointer)){
                if(!detector->checkBorderCollision(tankPointer, field->getColumnSize(), field->getRowSize())) alright = true;
                else uiHandler->printMessage("Oh no! Your tank would fall of the battlefield. Try again:");
            }
            else uiHandler->printMessage("I'm sorry Dave I'm afraid I can't do that... Try again:");
        }

        delete location;

        warObjectList.push_back(tankPointer);
        system("cls");
    }

    uiHandler->printMessage("You are set to battle your enemy! Here is your army:");
    uiHandler->printWarObjects(warObjectList);

    field->reset();
    field->drawWarObjects(warObjectList);
    uiHandler->printMessage(field->generateField());
    system("pause");
    system("cls");
}

void HumanPlayer::yourTurn(){
    //Show the enemies field (All your fire locations that are hot or miss)
    //And ask what tank you want to use.
    uiHandler->printMessage("This is your view of the enemy's map.");
    if(getAllFiredBullets().empty()) uiHandler->printMessage("You have not fired any bullets yet.");

    field->reset();
    field->drawBullets(getAllFiredBullets());
    uiHandler->printMessage(field->generateField());
    uiHandler->printMessage("Your current arsenal: ");
    uiHandler->printWarObjects(warObjectList);

    //int tankNumber = uiHandler->askNumber("What tank do you want to use?:", 1, warObjectList.size());
    int tankNumber = 1; //Default to the first tank due to the current game design.

    //Ask what location you want to fire too
    Location * location;
    do{
         location = uiHandler->askLocation("Where do you want to shoot to? (eg. C5): ", field->getColumnSize(), field->getRowSize());
    }while(checkForReusedShootingLocation(location));

    //Save that fire location
    addFiredBullet(new Bullet(location->getXLocation(), location->getYLocation(), warObjectList[tankNumber-1]->getDamage()));
    uiHandler->printMessage("Firing the bullet!!... BOOOOOMMM ....");
    system("pause");
    system("cls");
}

void HumanPlayer::reportBullets(std::vector<Bullet *> bullets){
    incommingBullet(bullets.back());
    //Show  the players field with the hits/misses
    field->reset();
    field->drawWarObjects(warObjectList);
    field->drawBullets(bullets);
    uiHandler->printMessage(field->generateField());
    system("pause");
    system("cls");
}
