#include "Game.h"

Game::Game(){
    finished = false;

    //Init Uihandler
    uiHandler = new UiHandler();

    //Adding all Tanks
    generalWarObjectList.push_back(new DefaultTank());
    generalWarObjectList.push_back(new LaserTank());
    generalWarObjectList.push_back(new ArmouredTank());

    //Setting up the players
    playerOne = new HumanPlayer(500, generalWarObjectList, uiHandler);
    playerTwo = new AiPlayer(500, generalWarObjectList, uiHandler);

    //Show the generated AI field
    //playerTwo->setDebug(true);

    //Initing the Players
    playerTwo->init();
    playerOne->init();

}

Game::run(){
    if(!playerOne->isDead() || finished){
        playerOne->yourTurn();
        playerTwo->reportBullets(playerOne->getAllFiredBullets());
    }
    else{
        uiHandler->printEndScreen("Player 2 has WON!");
        finished = true;

    }

    if(!playerTwo->isDead() || finished){
        playerTwo->yourTurn();
        playerOne->reportBullets(playerTwo->getAllFiredBullets());
    }
    else{
        uiHandler->printEndScreen("Player 1 has WON!");
        finished = true;

    }
}

bool Game::isFinished(){
    return finished;
}

