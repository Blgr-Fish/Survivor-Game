#pragma once
#include "object/LivingObject2D.h"

class Player : public LivingObject2D {
    public:
        Player(int health, const std::string& spriteName,RessourceLoader& ressourceLoader);


        void move() override ;
        void update() override ;

        void setCameraSize(float sizeX,float sizeY);

        sf::View & getCamera() ;

        


    private:

        sf::View camera ;

};