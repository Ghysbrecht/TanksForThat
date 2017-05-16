#include "Player.h"

Player::Player(int credits, std::vector<WarObject *> generalWarObjectList, UiHandler * uiHandler)
{
    this->credits = credits;
    this->generalWarObjectList = generalWarObjectList;
    this->uiHandler = uiHandler;
    detector = new CollisionDetector();
    field = new Field();
    field->fillWith(' ');
    lastHitStatus = 0;
}


Player::addFiredBullet(Bullet * bullet){
    firedBullets.push_back(bullet);
}

Bullet * Player::getLastFiredBullet(){
    return firedBullets.back();
}

void Player::incommingBullet(Bullet * bullet){
    //WarObject * warObject = CollisionDetector::returnColidedObject(warObjectList, location);
    //if(warObject == nullptr) //No HIT
    //else //HIT!
}

Player::reportLastFireAtempt(int status){
    return lastHitStatus;
}

std::vector<Bullet *> Player::getAllFiredBullets(){
    return firedBullets;
}

