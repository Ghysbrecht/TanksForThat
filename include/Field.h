#pragma once
#include <string>
#include "WarObject.h"
#include <vector>
#include "Location.h"
#include "Bullet.h"


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
        void drawWarObjects(std::vector<WarObject *> warObjectList);
        void drawBullets(std::vector<Bullet *> bullets);
        void drawBullet(Bullet * bullet);

    public:
        std::string generateField();

    private:
        std::string generateColumnIdentifiers();

    public:
        int getRowSize();
        int getColumnSize();
};

