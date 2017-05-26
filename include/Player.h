#pragma once

#include "Field.h"
#include "UiHandler.h"
#include "WarObject.h"
#include "Location.h"
#include "CollisionDetector.h"

class Player
{
    protected:
        int credits;
        int lastHitStatus;

        Field * field;
        UiHandler * uiHandler;
        CollisionDetector * detector;
        std::vector<WarObject *> warObjectList;
        std::vector<WarObject *> generalWarObjectList;
        std::vector<Bullet *> firedBullets;

    public:
        Player(int credits, std::vector<WarObject *> generalWarObjectList, UiHandler * uiHandler);
        virtual void init() = 0;
        virtual void yourTurn() = 0;
        virtual void reportBullets(std::vector<Bullet *> bullets) = 0;
        void incommingBullet(Bullet * bullet);
        void deleteDeadObjects();

    public:
        void addFiredBullet(Bullet * bullet); //Add a location where you want to fire to

    public:
        Bullet * getLastFiredBullet();
        std::vector<Bullet *> getAllFiredBullets();
        int checkForReusedShootingLocation(Location * location);

};

