#pragma once
#include <string>
#include "WarObject.h"

class DefaultTank : public WarObject
{
    private:
        static const int DAMAGE = 50;
        static const int HEALTH = 100;
        static const int RANGE = 5;

        static const int COLUMNSIZE = 3;
        static const int ROWSIZE = 2;
        static const char IDENTIFIER = 'T';

        static const int ROWLOCATION = 0;
        static const int COLUMNLOCATION = 0;
        static const int TURNED = 0;

        static const int CREDITCOST = 200;

    public:
        DefaultTank();


};
