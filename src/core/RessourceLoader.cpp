#include "core/RessourceLoader.h"

std::map<std::string, sf::Texture> RessourceLoader::texturesMap;


RessourceLoader::RessourceLoader(sf::Font font, sf::Clock clock,
                                int height, int width, float gameSpeed )
    : p_GameFont(font),         
      p_GameClock(clock),
      p_GameWindow( sf::RenderWindow(sf::VideoMode({static_cast<unsigned int>(width), static_cast<unsigned int>(height)}), "Survivor !"))
{
}




const sf::Font& RessourceLoader::getFont() const {
    return p_GameFont;
}

sf::Clock& RessourceLoader::getClock() {
    return p_GameClock;
}


sf::RenderWindow& RessourceLoader::getRenderWindow() {
    return p_GameWindow;
}

sf::Texture& RessourceLoader::getTexture(const std::string& name){
    return texturesMap.at(name);
}

void RessourceLoader::addTexture(const std::string & name) {
    sf::Texture t(name);
    texturesMap.insert({name,t});
}


