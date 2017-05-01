#include "field.h"
#include <iostream>
#include "DefaultTank.h"
#include <string>
#include <cstdlib>

using namespace std;

Field* field;
WarObject* warobject;

int main()
{
    field = new Field();
    field->fillWith(' ');
    std::cout << field->generateField() << std::endl;

    warobject = new DefaultTank();
    field->drawWarObject(warobject);
    std::cout << field->generateField() << std::endl;

    field->reset();
    warobject->setLocation(3,4,0);
    field->drawWarObject(warobject);
    std::cout << field->generateField() << std::endl;


    do {
    int row;
    int column;
    int turned;
    std::cout << "Row Location: ";
    cin >> row;
    std::cout << "Column Location: ";
    cin >> column;
    std::cout << "90deg turned? (0:NO 1:YES): ";
    cin >> turned;

    field->reset();
    warobject->setLocation(row ,column, turned);
    field->drawWarObject(warobject);
    std::cout << field->generateField() << std::endl;


  } while (1);
}
