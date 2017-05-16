#pragma once
#include <string>
#include "WarObject.h"

class LaserTank : public WarObject
{
    private:
        static const int DAMAGE = 100;
        static const int HEALTH = 50;
        static const int RANGE = 15;

        static const int COLUMNSIZE = 2;
        static const int ROWSIZE = 1;
        static const char IDENTIFIER = 'L';

        static const int ROWLOCATION = 0;
        static const int COLUMNLOCATION = 0;
        static const int TURNED = 0;

        static const int CREDITCOST = 200;

    public:
        LaserTank();


};
