#pragma once

#include "WarObject.h"
#include "Location.h"
#include <vector>

class CollisionDetector
{
    public:
        WarObject * returnCollidedObject( std::vector<WarObject *> warObjectList, Location * location );
        int checkBorderCollision(WarObject * warObject);
};

