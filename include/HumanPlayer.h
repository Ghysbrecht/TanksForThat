#pragma once

#include "player.h"
#include "WarObject.h"

class HumanPlayer : public Player
{
    public:
        HumanPlayer(int credits, std::vector<WarObject *> generalWarObjectList, UiHandler * uiHandler);
        virtual void init();
        virtual void yourTurn();
        void checkLastEvents();
        virtual void reportBullets(std::vector<Bullet *> bullets);

};

