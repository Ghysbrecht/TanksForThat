#include "LaserTank.h"

LaserTank::LaserTank() : WarObject(DAMAGE, HEALTH, RANGE)
{
    setLocation(ROWLOCATION, COLUMNLOCATION, TURNED);
    setObjectSize(ROWSIZE, COLUMNSIZE, IDENTIFIER);
    setName("Laser");
    setCreditCost(CREDITCOST);
}



