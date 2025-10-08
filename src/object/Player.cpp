#include "object/Player.h"

Player::Player(int health, const std::string& spriteName,RessourceLoader& ressourceLoader) 
    :LivingObject2D(
                630, 
                360,
                5,  
                health,
                spriteName,
                ressourceLoader
                ) 
    {}



void Player::move() {

}


void Player::update() {
    this->move();
}

