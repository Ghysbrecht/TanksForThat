#pragma once
#include <string>

class WarObject
{
    private:
        int damage;
        int health;
        int range;

        int rowLocation;
        int columnLocation;
        int turned;

        int rowSize;
        int columnSize;

        std::string name;
        char identifier;

    public:
        WarObject(int damage, int health, int range);

    public:
        void setLocation(int row, int column, int turned);
        void setObjectSize(int rowSize, int columnSize, char identifier);

    public:
        int getRowLocation();
        int getColumnLocation();
        int getRowSize();
        int getColumnSize();
        int getTurned();
        char getIdentifier();
};
