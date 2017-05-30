#include "Field.h"
#include <sstream>
#include <stdio.h>


Field::Field(){
}


void Field::fillWith(char character){
    for(int i=0;i<ROWS;i++){
        for(int j=0;j<COLUMNS;j++){
            fieldArray[i][j] = character;
        }
    }
}

std::string Field::generateField(){
    std::stringstream ss;
    ss << " " << generateTopBar();
    ss << " " << (char)186 << " " << generateColumnIdentifiers() << " " << (char)186 << std::endl;
    for(int i=0;i<ROWS;i++){
        ss << " " << (char)186 << " " << i;
        for(int j=0;j<COLUMNS;j++) ss << " " << fieldArray[i][j];
        ss << " " << (char)186 << std::endl;
    }
    ss << " " << generateBottomBar();
    return ss.str();
}

std::string Field::generateColumnIdentifiers(){
    std::stringstream ss;
    char columnIdentifier = 'A';
    ss << " ";
    for(int j=0;j<COLUMNS;j++){
        ss << " " << columnIdentifier;
        columnIdentifier++;
    }
    return ss.str();
}

void Field::drawWarObject(WarObject* warobject){

    int columnLocation = warobject->getColumnLocation();
    int rowLocation = warobject->getRowLocation();
    int columnSize = warobject->getColumnSize();
    int rowSize = warobject->getRowSize();
    char identifier = warobject->getIdentifier();

    if(warobject->getTurned()){
        int temp = columnSize;
        columnSize = rowSize;
        rowSize = temp;
    }

    for(int i=rowLocation; i<(rowLocation+rowSize); i++){
        for(int j=columnLocation; j<(columnLocation+columnSize); j++)
            fieldArray[i][j] = identifier;
    }
}

void Field::reset(){
    fillWith(' ');
}

void Field::drawWarObjects(std::vector<WarObject *> warObjectList){
    for(int i = 0; i<warObjectList.size(); i++){
        drawWarObject(warObjectList[i]);
    }
}

int Field::getRowSize(){
    return ROWS;
}
int Field::getColumnSize(){
    return COLUMNS;
}

void Field::drawBullets(std::vector<Bullet *> bullets){
    for(int i = 0; i<bullets.size(); i++){
        drawBullet(bullets[i]);
    }
}

void Field::drawBullet(Bullet * bullet){
    fieldArray[bullet->getYLocation()][bullet->getXLocation()] = bullet->getSymbol();
}

std::string Field::generateTopBar(){
    std::stringstream ss;
    ss << (char)201;
    for(int j=0;j<=((COLUMNS*2)+2);j++) ss << (char)205;
    ss << (char)187;
    ss << std::endl;
    return ss.str();
}

std::string Field::generateBottomBar(){
    std::stringstream ss;
    ss << (char)200;
    for(int j=0;j<=((COLUMNS*2)+2);j++) ss << (char)205;
    ss << (char)188;
    ss << std::endl;
    return ss.str();
}
