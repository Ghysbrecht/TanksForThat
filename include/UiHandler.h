#pragma once
#include "WarObject.h"
#include <vector>
#include <sstream>

class UiHandler
{
    public:
        UiHandler();


    public:
        std::string printWarObjects(std::vector<WarObject *> warObjectList);
        std::string printWarObject(WarObject* warObject);
};

