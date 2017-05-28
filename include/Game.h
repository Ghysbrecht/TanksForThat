#pragma once

#include "DefaultTank.h"
#include "LaserTank.h"
#include <vector>
#include "UiHandler.h"
#include "Player.h"
#include "HumanPlayer.h"
#include "AiPlayer.h"
#include "ArmouredTank.h"

class Game
{
    private:
        bool finished;
        UiHandler* uiHandler;
        Player * playerOne;
        Player * playerTwo;
        std::vector<WarObject *> generalWarObjectList;

    public:
        Game();
        run();

    public:
        bool isFinished();
};


