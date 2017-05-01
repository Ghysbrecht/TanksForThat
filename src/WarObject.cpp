#include "WarObject.h"

WarObject::WarObject(int damage, int health, int range)
{
    this->damage = damage;
    this->health = health;
    this->range = range;
}


void WarObject::setLocation(int row, int column, int turned){
    this->rowLocation = row;
    this->columnLocation = column;
    this->turned = turned;
}

void WarObject::setObjectSize(int row, int column, char identifier){
    this->rowSize = row;
    this->columnSize = column;
    this->identifier = identifier;
}

int WarObject::getRowLocation(){
    return this->rowLocation;
}
int WarObject::getColumnLocation(){
    return this->columnLocation;
}
int WarObject::getRowSize(){
    return this->rowSize;
}
int WarObject::getColumnSize(){
    return this->columnSize;
}
int WarObject::getTurned(){
    return this->turned;
}
char WarObject::getIdentifier(){
    return this->identifier;
}
