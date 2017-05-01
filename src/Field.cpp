#include "Field.h"
#include <sstream>
#include <stdio.h>


Field::Field()
{

}

Field::~Field()
{
    //dtor
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

    ss << generateColumnIdentifiers();

    for(int i=0;i<ROWS;i++){
        ss << i;
        for(int j=0;j<COLUMNS;j++){
            ss << " " << fieldArray[i][j];
        }
        ss << std::endl;
    }
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
    ss << std::endl;

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
