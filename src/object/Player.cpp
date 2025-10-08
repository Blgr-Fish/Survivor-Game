#include "object/Player.h"

Player::Player(int health, const std::string& spriteName,RessourceLoader& ressourceLoader) 
    :LivingObject2D(
                630, 
                360,
                16,  
                health,
                spriteName,
                ressourceLoader
                ) 
    {}



void Player::move() {
    int newXCoord = xCoordinate ;
    int newYCoord = yCoordinate ;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Z)) {
        newYCoord -= speed;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) {
        newYCoord += speed;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Q)) {
        newXCoord -= speed;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {
        newXCoord += speed;
    }

    setPosition(newXCoord,newYCoord);
}


void Player::update() {
    this->move();
}

