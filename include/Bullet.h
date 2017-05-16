#pragma once
#include "Location.h"

class Bullet
{
    private:
        int damage;
        char symbol;
        Location * location;

    public:
        Bullet(int fireToX, int fireToY, int damage);

    public:
        char getSymbol();
        int getDamage();
        int getXLocation();
        int getYLocation();

    public:
        void setSymbol(char symbol);
};

