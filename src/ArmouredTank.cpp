#include "ArmouredTank.h"

ArmouredTank::ArmouredTank() : WarObject(DAMAGE, HEALTH, RANGE)
{
    setLocation(ROWLOCATION, COLUMNLOCATION, TURNED);
    setObjectSize(ROWSIZE, COLUMNSIZE, IDENTIFIER);
    setName("Panzerkampfwagen");
    setCreditCost(CREDITCOST);
}


