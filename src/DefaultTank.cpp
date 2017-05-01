#include "DefaultTank.h"

DefaultTank::DefaultTank() : WarObject(DAMAGE, HEALTH, RANGE)
{
    setLocation(ROWLOCATION, COLUMNLOCATION, TURNED);
    setObjectSize(ROWSIZE, COLUMNSIZE, IDENTIFIER);
    setName("Destroyer");
}


