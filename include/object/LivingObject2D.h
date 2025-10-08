#pragma once 

#include "object/Object2D.h"

class LivingObject2D : public Object2D {
    public:

        LivingObject2D(int x, int y, int speed, int health, const std::string& spriteName,RessourceLoader& ressourceLoader)
                : Object2D(x, y, speed, spriteName, ressourceLoader), healthPoints(health), isAlive(true) {}

        LivingObject2D(int health, const std::string& spriteName,RessourceLoader& ressourceLoader)
                : Object2D(spriteName, ressourceLoader), healthPoints(health), isAlive(true) {}

        int getHealthPoints() const {return healthPoints;}
        bool checkIsAlive() const {return isAlive;}
        void setStatus(bool status) { this->isAlive = status ;}
    
    protected:
        int healthPoints;
        bool isAlive;

};  