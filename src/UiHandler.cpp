#include "UiHandler.h"

UiHandler::UiHandler()
{

}

std::string UiHandler::printWarObjects(std::vector<WarObject *> warObjectList){
    std::stringstream ss;
    for(int i = 0; i<warObjectList.size(); i++){
        ss << printWarObject(warObjectList[i]);
    }
    return ss.str();
}

std::string UiHandler::printWarObject(WarObject* warObject){
    std::stringstream ss;
    ss << warObject->getName();
    ss << "  Damage: " << warObject->getDamage();
    ss << "  Range: " << warObject->getRange();
    ss << "  Health: " << warObject->getHealth();
    ss << std::endl;
    return ss.str();
}
