#pragma once

#include "player.h"
#include "WarObject.h"

class AiPlayer : public Player
{
    public:
        AiPlayer(int credits, std::vector<WarObject *> generalWarObjectList, UiHandler * uiHandler);
        virtual void init();
        virtual void yourTurn();
        void checkLastEvents();
        int getRandomInt(int minim, int maxim);

};

