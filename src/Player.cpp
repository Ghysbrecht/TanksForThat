#include "Player.h"
#include <sstream>
#include <cstdlib>

Player::Player(int credits, std::vector<WarObject *> generalWarObjectList, UiHandler * uiHandler)
{
    this->credits = credits;
    this->generalWarObjectList = generalWarObjectList;
    this->uiHandler = uiHandler;
    detector = new CollisionDetector();
    field = new Field();
    field->fillWith(' ');
    lastHitStatus = 0;
    debug = false;
}


void Player::addFiredBullet(Bullet * bullet){
    firedBullets.push_back(bullet);
}

Bullet * Player::getLastFiredBullet(){
    return firedBullets.back();
}

void Player::incommingBullet(Bullet * bullet){
    Location * location = new Location(bullet->getXLocation(), bullet->getYLocation());
    WarObject * warObject = detector->returnCollidedObject(warObjectList, location);
    if(warObject == nullptr){
       bullet->setSymbol('M');
       uiHandler->printMiss();
    }
    else{
        bullet->setSymbol('H');
        uiHandler->printHit(warObject->getName());
        warObject->doDamage(bullet->getDamage());
    }
    //Check if there are dead tanks
    deleteDeadObjects();
    delete location;
}

std::vector<Bullet *> Player::getAllFiredBullets(){
    return firedBullets;
}

void Player::deleteDeadObjects(){
    for(int i=0; i<warObjectList.size(); i++ ){
        if(warObjectList[i]->getHealth() == 0){
            std::stringstream ss;
            uiHandler->printDestroyedTank(warObjectList[i]->getName());
            warObjectList.erase(warObjectList.begin()+i);
        }
    }
}

int Player::checkForReusedShootingLocation(Location * location){
    for(int i=0; i<firedBullets.size(); i++){
        if((location->getXLocation() == firedBullets[i]->getXLocation()) && (location->getYLocation() == firedBullets[i]->getYLocation())) return 1;
    }
    return 0;
}

void Player::setDebug(bool status){
    debug = status;
}
