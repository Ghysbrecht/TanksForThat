#pragma once
#include "WarObject.h"
#include <vector>
#include <sstream>
#include <iostream>
#include "Location.h"

class UiHandler
{
    private:
        int consoleWidth;
    public:
        UiHandler();


    public:
        printWarObjects(std::vector<WarObject *> warObjectList);
        printWarObject(WarObject* warObject);
        printStartScreen();
        printMessage(std::string message);
        printNumber(std::string message, int value);
        printDestroyedTank(std::string tankName);
        printHit(std::string tankName);
        printMiss();
        printEndScreen(std::string message);
        printTankSize(WarObject* warObject);
        printTitle(std::string message);
        setDefaultColor();
        newLine();

    public:
        int askNumber(std::string message, int minimum, int maximum);
        Location * askLocation(std::string message, int maxX, int maxY);
        std::string centerText(std::string text);
        std::string returnDestroyed(std::string tankName);
        std::string returnHit(std::string tankName);
};

