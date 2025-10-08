#pragma once

#include "graphics/Sprite.h"



class Object2D {

    public:
        Object2D(int x, int y, int speed, const std::string& spriteName, RessourceLoader & ressourceLoader) 
            : xCoordinate(x), 
            yCoordinate(y), 
            speed(speed), 
            objectSprite(spriteName,ressourceLoader) {}

        Object2D( const std::string& spriteName, RessourceLoader & ressourceLoader) 
            : xCoordinate(0), yCoordinate(0), speed(0), objectSprite(spriteName,ressourceLoader) {}

        virtual ~Object2D() {}  

        int getXCoordinate() const { return xCoordinate; }
        int getYCoordinate() const { return yCoordinate; }
        int getSpeed() const { return speed; }

        void updateSpeed(int speed) {this->speed = speed;}

        virtual void update() const = 0;


    protected:
        int xCoordinate;
        int yCoordinate;
        int speed ;

        Sprite objectSprite;
};