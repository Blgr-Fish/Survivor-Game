#pragma once

#include "graphics/Sprite.h"



class Object2D {

    public:
        Object2D(int x, int y, int speed, const std::string& spriteName, RessourceLoader & ressourceLoader) 
            : xCoordinate(x), 
            yCoordinate(y), 
            speed(speed), 
            objectSprite(spriteName,ressourceLoader) {

                sf::Sprite& spr = objectSprite.getSprite();
                sf::Vector2u texSize = spr.getTexture().getSize(); 
                spr.setScale(sf::Vector2f{32.f / texSize.x, 32.f / texSize.y } );
                spr.setPosition(sf::Vector2f{(float)xCoordinate,(float)yCoordinate});
            }

        Object2D( const std::string& spriteName, RessourceLoader & ressourceLoader) 
            : xCoordinate(0), yCoordinate(0), speed(0), objectSprite(spriteName,ressourceLoader) {}

        virtual ~Object2D() {}  

        int getXCoordinate() const { return xCoordinate; }
        int getYCoordinate() const { return yCoordinate; }
        int getSpeed() const { return speed; }

        void updateSpeed(int speed) {this->speed = speed;}

        void setPosition(int newX, int newY) { 
            this->xCoordinate = newX;
            this->yCoordinate = newY; 
            objectSprite.getSprite().setPosition(sf::Vector2f{(float)xCoordinate,(float)yCoordinate});}

        Sprite getSpriteObject() { return this->objectSprite;}

    

        virtual void update() = 0;




    protected:
        int xCoordinate;
        int yCoordinate;
        int speed ;

        Sprite objectSprite;
};