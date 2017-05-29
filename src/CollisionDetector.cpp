#include "CollisionDetector.h"
#include <stdio.h>

WarObject * CollisionDetector::returnCollidedObject(std::vector<WarObject *> warObjectList, Location * location){

    for(int i=0; i < warObjectList.size(); i++){

        //printf("Starting the collision detection for tank nr. %i\n",i);

        int warObjectX = warObjectList[i]->getColumnLocation();
        int warObjectY = warObjectList[i]->getRowLocation();

        int locationX = location->getXLocation();
        int locationY = location->getYLocation();

        int xLength = warObjectList[i]->getColumnSize();
        int yLength = warObjectList[i]->getRowSize();
        int turned = warObjectList[i]->getTurned();

        //printf("ObjecLocation     -> x:%i y:%i\n",warObjectX, warObjectY);
        //printf("Shooting Location -> x:%i y:%i\n",locationX, locationY);
        //printf("Length of object  -> x:%i y:%i\n",xLength, yLength);
        //printf("Object is turned? -> %i\n", turned);

        if(turned){
            int temp = xLength;
            xLength = yLength;
            yLength = temp;
        }

        for(int j=0; j < xLength; j++){
            for(int k=0; k < yLength; k++){
                //printf("Scanning x=%i y=%i \n", warObjectX+j, warObjectY+k);
                if(locationX == (warObjectX + j) && locationY == (warObjectY + k)){
                    //Hit detected!
                    //printf("HIT DETECTED!\n");
                    return warObjectList[i];
                }
            }
        }

    }

}

int CollisionDetector::checkObjectCollision(std::vector<WarObject *> warObjectList, WarObject * warObject){
    int columnSize = warObject->getColumnSize();
    int rowSize = warObject->getRowSize();
    if(warObject->getTurned()){
        int temp = rowSize;
        rowSize = columnSize;
        columnSize = temp;
    }
    for(int i=0; i<columnSize; i++){
        for(int j=0; j<rowSize; j++){
            Location * location = new Location(i+warObject->getColumnLocation(), j+warObject->getRowLocation());
            if(returnCollidedObject(warObjectList, location) != nullptr){
                delete location;
                return 1;
            }
            delete location;
        }
    }
    return 0;
}

int CollisionDetector::checkBorderCollision(WarObject * warObject, int fieldColSize, int fieldRowSize){
    if(warObject->getColumnLocation() + warObject->getColumnSize() <= fieldColSize && warObject->getRowLocation() + warObject->getRowSize() <= fieldRowSize && warObject->getTurned() == 0 ) return 0;
    else if(warObject->getColumnLocation() + warObject->getRowSize() <= fieldColSize && warObject->getRowLocation() + warObject->getColumnSize() <= fieldRowSize && warObject->getTurned() == 1 ) return 0;
    else return 1;
}

