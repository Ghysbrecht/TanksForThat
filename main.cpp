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
#include "AiPlayer.h"

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
    Player * playerTwo = new AiPlayer(1000, generalWarObjectList, uiHandler);

    playerTwo->init();
    playerOne->init();
    while(1){
    playerOne->yourTurn();
    //Should be playertwo
    playerOne->incommingBullet(playerOne->getLastFiredBullet());
    //playerOne->checkLastEvents();
    }

}
