#include "Bullet.h"

Bullet::Bullet(int x, int y, int damage)
{
    location = new Location(x, y);
    this->damage = damage;
    symbol = 'F';
}


char Bullet::getSymbol(){
    return symbol;
}

void Bullet::setSymbol(char symbol){
    this->symbol = symbol;
}

int Bullet::getXLocation(){
    return location->getXLocation();
}

int Bullet::getYLocation(){
    return location->getYLocation();
}

int Bullet::getDamage(){
    return damage;
}
