#pragma once

#include "WarObject.h"
#include "Location.h"
#include <vector>

class CollisionDetector
{
    public:
        WarObject * returnCollidedObject( std::vector<WarObject *> warObjectList, Location * location );
        int checkObjectCollision(std::vector<WarObject *> warObjectList, WarObject * warObject);
        int checkBorderCollision(WarObject * warObject, int fieldColSize, int fieldRowSize);
};


