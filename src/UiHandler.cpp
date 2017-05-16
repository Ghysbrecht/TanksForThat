#include "UiHandler.h"


UiHandler::UiHandler()
{

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
    std::stringstream ss;
    ss << warObject->getName() << " - ";
    ss << " Damage: " << warObject->getDamage();
    ss << " | Range: " << warObject->getRange();
    ss << " | Health: " << warObject->getHealth();
    ss << " | Cost: " << warObject->getCreditCost();
    std::cout << ss.str();
}

UiHandler::printStartScreen(){
    std::stringstream ss;
    ss << "  _______             _         " << std::endl;
    ss << " |__   __|           | |        " << std::endl;
    ss << "    | |  __ _  _ __  | | __  ___" << std::endl;
    ss << "    | | / _` || '_ \\ | |/ // __|" << std::endl;
    ss << "    | || (_| || | | ||   < \\__ \\" << std::endl;
    ss << "  __|_|_\\__,_||_| |_||_|\\_\\|___/" << std::endl;
    ss << " |  ____|                       " << std::endl;
    ss << " | |__  ___   _ __              " << std::endl;
    ss << " |  __|/ _ \ | '__|             " << std::endl;
    ss << " | |  | (_) || |                " << std::endl;
    ss << " |_|___\\___/ |_|         _      " << std::endl;
    ss << " |__   __|| |           | |     " << std::endl;
    ss << "    | |   | |__    __ _ | |_    " << std::endl;
    ss << "    | |   | '_ \\  / _` || __|   " << std::endl;
    ss << "    | |   | | | || (_| || |_    " << std::endl;
    ss << "    |_|   |_| |_| \\__,_| \\__|   " << std::endl;
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
    }while( yLocation > maxY || xLocation > maxX || yLocation < 0 ||xLocation < 0 );

    Location * location = new Location(xLocation, yLocation);
    return location;
}
