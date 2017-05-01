#include "field.h"
#include <iostream>
#include "DefaultTank.h"
#include <string>
#include <cstdlib>
#include <vector>
#include "UiHandler.h"


using namespace std;

Field* field;
UiHandler* uiHandler;

std::vector<WarObject *> warObjectList;

int main()
{
    //Init Uihandler
    uiHandler = new UiHandler();

    //Init field
    field = new Field();
    field->fillWith(' ');

    //Adding Tanks
    warObjectList.push_back(new DefaultTank());
    warObjectList.push_back(new DefaultTank());
    warObjectList.push_back(new DefaultTank());

    //Setting tank locations
    warObjectList[1]->setLocation(3,4,0);
    warObjectList[2]->setLocation(7,5,1);

    //Drawing tanks
    field->drawWarObjects(warObjectList);
    std::cout << field->generateField() << std::endl;

    //Showing the tank stats
    std::cout << uiHandler->printWarObjects(warObjectList) << std::endl;

}
