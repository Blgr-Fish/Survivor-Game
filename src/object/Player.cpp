#include "object/Player.h"

Player::Player(int health, const std::string& spriteName,RessourceLoader& ressourceLoader) 
    :LivingObject2D(
                630, 
                360,
                8,  
                health,
                spriteName,
                ressourceLoader
                ) ,
     camera()
    {
        camera.setCenter(sf::Vector2f{(float)xCoordinate,(float)yCoordinate});
    }



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
    camera.setCenter(sf::Vector2f{(float)newXCoord,(float)newYCoord});
}


void Player::update() {
    this->move();
}

void Player::setCameraSize(float sizeX,float sizeY) {
    camera.setSize(sf::Vector2f{sizeX,sizeY});
}

sf::View  & Player::getCamera() { return this->camera;}