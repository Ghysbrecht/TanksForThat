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
int WarObject::getRange(){
    return this->range;
}
int WarObject::getHealth(){
    return this->health;
}
int WarObject::getDamage(){
    return this->damage;
}
int WarObject::getCreditCost(){
    return this->creditCost;
}
void WarObject::setCreditCost(int creditCost){
    this->creditCost = creditCost;
}
void WarObject::setName(std::string name){
    this->name = name;
}
std::string WarObject::getName(){
    return this->name;
}

void WarObject::doDamage(int damage){
    this->health -= damage;
    if(this->health < 0) this->health = 0;
}
