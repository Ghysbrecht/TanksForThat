#pragma once
#include <string>
#include "WarObject.h"

class ArmouredTank : public WarObject
{
    private:
        static const int DAMAGE = 50;
        static const int HEALTH = 600;
        static const int RANGE = 5;

        static const int COLUMNSIZE = 3;
        static const int ROWSIZE = 2;
        static const char IDENTIFIER = 'A';

        static const int ROWLOCATION = 0;
        static const int COLUMNLOCATION = 0;
        static const int TURNED = 0;

        static const int CREDITCOST = 300;

    public:
        ArmouredTank();


};
