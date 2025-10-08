#pragma once
#include <SFML/Graphics.hpp>
#include "core/RessourceLoader.h"


class Sprite {
    public:
        Sprite(const std::string textureName, RessourceLoader & r) :
            sprite(r.getTexture(textureName)){}

        sf::Sprite getSprite() const {return this->sprite;}

        void updateSprite(const sf::Texture& newTexture) { this->sprite.setTexture(newTexture);}

    private:
        sf::Sprite sprite ;
};