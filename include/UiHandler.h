#pragma once
#include "WarObject.h"
#include <vector>
#include <sstream>
#include <iostream>
#include "Location.h"

class UiHandler
{
    public:
        UiHandler();


    public:
        printWarObjects(std::vector<WarObject *> warObjectList);
        printWarObject(WarObject* warObject);
        printStartScreen();
        printMessage(std::string message);
        printNumber(std::string message, int value);
        newLine();

    public:
        int askNumber(std::string message, int minimum, int maximum);
        Location * askLocation(std::string message, int maxX, int maxY);



};

