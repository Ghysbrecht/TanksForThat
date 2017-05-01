#pragma once
#include <string>
#include "WarObject.h"



class Field
{
    private:
        static const int ROWS = 10;
        static const int COLUMNS = 10;
        char fieldArray[ROWS][COLUMNS];

    public:
        Field();
        virtual ~Field();

    public:
        void reset();
        void fillWith(char character);
        void drawWarObject(WarObject* warobject);

    public:
        std::string generateField();

    private:
        std::string generateColumnIdentifiers();
};

