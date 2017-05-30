#include "UiHandler.h"
#include <cstdlib>

UiHandler::UiHandler()
{
    consoleWidth = 80;
}

UiHandler::printWarObjects(std::vector<WarObject *> warObjectList){
    std::stringstream ss;
    for(int i = 0; i<warObjectList.size(); i++){
        std::cout << i+1 << ": ";
        printWarObject(warObjectList[i]);
        std::cout << std::endl;
    }
    std::cout << std::endl;
}


UiHandler::printWarObject(WarObject* warObject){
    std::string warObjectName = warObject->getName();
    for(int i = warObjectName.size(); i < 18; i++) warObjectName.append(" ");
    std::stringstream ss;
    ss << warObjectName << " - ";
    ss << " Damage: " << warObject->getDamage();
    //ss << " | Range: " << warObject->getRange();
    ss << " | Health: " << warObject->getHealth();
    ss << " | Cost: " << warObject->getCreditCost();
    std::cout << ss.str();
}

UiHandler::printStartScreen(){
    std::stringstream ss;
    ss << centerText(" _______             _         ") << std::endl;
    ss << centerText("|__   __|           | |        ") << std::endl;
    ss << centerText("   | |  __ _  _ __  | | __ ___ ") << std::endl;
    ss << centerText("   | | / _` || '_ \\ | |/ // __|") << std::endl;
    ss << centerText("   | || (_| || | | ||   < \\__ \\") << std::endl;
    ss << centerText(" __|_|_\\__,_||_| |_||_|\\_\\|___/") << std::endl;
    ss << centerText("|  ____|                       ") << std::endl;
    ss << centerText("| |__  ___   _ __              ") << std::endl;
    ss << centerText("|  __|/ _ \\ | '__|             ") << std::endl;
    ss << centerText("| |  | (_) || |                ") << std::endl;
    ss << centerText("|_|___\\___/ |_|         _      ") << std::endl;
    ss << centerText("|__   __|| |           | |     ") << std::endl;
    ss << centerText("   | |   | |__    __ _ | |_    ") << std::endl;
    ss << centerText("   | |   | '_ \\  / _` || __|   ") << std::endl;
    ss << centerText("   | |   | | | || (_| || |_    ") << std::endl;
    ss << centerText("   |_|   |_| |_| \\__,_| \\__|   ") << std::endl;
    ss << std::endl << std::endl;
    ss << std::endl;
    std::cout << ss.str();
}

int UiHandler::askNumber(std::string message, int minimum, int maximum){
    int tempNum;
    do{
        tempNum = 0;
        std::cout << message.c_str() << std::endl;
        std::string tempString;
        std::cin >> tempString;
        tempNum = (int)(tempString.at(0) - '0');
    }while(tempNum < minimum || tempNum > maximum);
    return tempNum;
}

UiHandler::printMessage(std::string message){
    std::cout << message << std::endl;
}

UiHandler::printNumber(std::string message, int value){
    std::stringstream ss;
    ss << message << value << std::endl;
    std::cout << ss.str();
}

UiHandler::newLine(){
    std::cout << std::endl;
}

Location * UiHandler::askLocation(std::string message, int maxX, int maxY){
    int xLocation;
    int yLocation;

    do{
        xLocation = 0;
        yLocation = 0;
        std::string input;
        do{
            std::cout << message << std::endl;
            std::cin >> input;
        }while(input.length() < 2);
        xLocation = (int)(input.at(0) - 'A');
        yLocation = (int)(input.at(1) - '0');
    }while( yLocation >= maxY || xLocation >= maxX || yLocation < 0 ||xLocation < 0 );

    Location * location = new Location(xLocation, yLocation);
    return location;
}

UiHandler::printDestroyedTank(std::string tankName){
    std::cout << centerText(returnDestroyed(tankName)) << std::endl;
}

UiHandler::printHit(std::string tankName){
    std::stringstream ss;
    ss << centerText(" _   _ ___ _____ ") << std::endl;
    ss << centerText("| | | |_ _|_   _|") << std::endl;
    ss << centerText("| |_| || |  | |  ") << std::endl;
    ss << centerText("|  _  || |  | |  ") << std::endl;
    ss << centerText("|_| |_|___| |_|  ") << std::endl;
    ss << std::endl;
    ss << centerText(returnHit(tankName)) << std::endl;
    std::cout << ss.str();

}

UiHandler::printMiss(){
std::stringstream ss;
ss << centerText(" __  __ ___ ____ ____  ") << std::endl;
ss << centerText("|  \\/  |_ _/ ___/ ___| ") << std::endl;
ss << centerText("| |\\/| || |\\___ \\___ \\ ") << std::endl;
ss << centerText("| |  | || | ___) ___) |") << std::endl;
ss << centerText("|_|  |_|___|____|____/ ") << std::endl;
ss << std::endl;
std::cout << ss.str();
}

UiHandler::printEndScreen(std::string message){
std::stringstream ss;
ss << centerText("   _____          __  __ ______    ______      ________ _____   ") << std::endl;
ss << centerText("  / ____|   /\\   |  \\/  |  ____|  / __ \\ \\    / /  ____|  __ \\  ") << std::endl;
ss << centerText(" | |  __   /  \\  | \\  / | |__    | |  | \\ \\  / /| |__  | |__) | ") << std::endl;
ss << centerText(" | | |_ | / /\\ \\ | |\\/| |  __|   | |  | |\\ \\/ / |  __| |  _  /  ") << std::endl;
ss << centerText(" | |__| |/ ____ \\| |  | | |____  | |__| | \\  /  | |____| | \\ \\  ") << std::endl;
ss << centerText("  \\_____/_/    \\_\\_|  |_|______|  \\____/   \\/   |______|_|  \\_\\ ") << std::endl;
ss << std::endl << std::endl;
ss << centerText("Game has ended!") << std::endl;
ss << centerText(message) << std::endl << std::endl << std::endl;
std::cout << ss.str();
}

UiHandler::printTankSize(WarObject* warObject){
    std::stringstream ss;
    std::string tempString = "";
    for(int i=0; i<warObject->getRowSize(); i++){
        for(int j=0; j<warObject->getColumnSize(); j++){
                tempString.push_back(warObject->getIdentifier());
                tempString.push_back(' ');
        }
        ss << centerText(tempString) << std::endl;
        tempString = "";
    }
    std::cout << ss.str();
}

UiHandler::setDefaultColor(){
    system("Color 07");
}

std::string UiHandler::centerText(std::string text){
    int tempNumber = (int)(consoleWidth - text.size())/2;
    if(tempNumber > 0) for(int i = 0; i < tempNumber ; i++) text.insert(0," ");
    return text;
}

std::string UiHandler::returnDestroyed(std::string tankName){
    std::stringstream ss;
    ss << "A " << tankName << " has been destroyed!";
    return ss.str();
}

std::string UiHandler::returnHit(std::string tankName){
    std::stringstream ss;
    ss << "A " << tankName << " has been hit!";
    return ss.str();
}

UiHandler::printTitle(std::string message){
    std::stringstream ss;
    ss << (char)201;
    for(int i=0; i<78; i++) ss << (char)205;
    ss << (char)187;
    ss << centerText(message) << std::endl;
    ss << (char)200;
    for(int i=0; i<78; i++) ss << (char)205;
    ss << (char)188;
    std::cout << ss.str();
}


