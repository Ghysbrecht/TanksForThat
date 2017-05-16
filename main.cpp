#include <iostream>
#include "DefaultTank.h"
#include "LaserTank.h"
#include <string>
#include <cstdlib>
#include <vector>
#include "UiHandler.h"
#include "Player.h"
#include "HumanPlayer.h"
#include "CollisionDetector.h"

UiHandler* uiHandler;

std::vector<WarObject *> generalWarObjectList;

int main()
{

    //Init Uihandler
    uiHandler = new UiHandler();

    //Adding all Tanks
    generalWarObjectList.push_back(new DefaultTank());
    generalWarObjectList.push_back(new LaserTank());

    Player * playerOne = new HumanPlayer(400, generalWarObjectList, uiHandler);

    playerOne->init();
    playerOne->yourTurn();

}
