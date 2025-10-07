#pragma once
#include <SFML/Graphics.hpp>
#include "RessourceLoader.h"


class Sprite {
    public:
        Sprite(const std::string texture, RessourceLoader & r) :
            sprite(r.getTexture(texture)){}

        sf::Sprite getSprite() const {return this->sprite;}

        void updateSprite(const sf::Texture& newTexture) { this->sprite.setTexture(newTexture);}

    private:
        sf::Sprite sprite ;
};