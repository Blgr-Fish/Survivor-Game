#include "object/Dummy.h"

Dummy::Dummy(int x, int y,RessourceLoader & ressourceLoader ,Player & player) :
    Monster(x,y,0,9999,"null", ressourceLoader,player){}


void Dummy::move() {
    this->setPosition(this->xCoordinate, this->yCoordinate);
}

void Dummy::update() {
    move();
}