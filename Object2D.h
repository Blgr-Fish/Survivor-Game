#pragma once

#include "Sprite.h"
#include "RessourceLoader.h"


class Object2D {

    public:
        Object2D(int x, int y, int speed, std::string spriteName) 
            : xCoordinate(x), yCoordinate(y), speed(speed), ObjectSprite(RessourceLoader.getTexture(spriteName)) {}

        Object2D() 
            : xCoordinate(0), yCoordinate(0), speed(0) {}

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

        Sprite ObjectSprite;
};