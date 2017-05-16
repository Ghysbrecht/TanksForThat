#include "HumanPlayer.h"
#include <cstdlib>
#include "DefaultTank.h"
#include "LaserTank.h"

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
        }
        warObjectList.push_back(tankPointer);

        system("cls");
        uiHandler->printMessage("Place your newly purchased tank. Make sure to not place them outside the area or on other tanks.");
        uiHandler->newLine();

        //Show the field
        field->reset();
        field->drawWarObjects(warObjectList);
        uiHandler->printMessage(field->generateField());


        Location * location = uiHandler->askLocation("Enter the coordinates (eg. C5): ", field->getColumnSize() - tankPointer->getColumnSize(), field->getRowSize() - tankPointer->getRowSize());
        warObjectList.back()->setLocation(location->getYLocation(), location->getXLocation(), 0);
        delete location;

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
    //Ask what location you want to fire too

    //Save that fire location
}
