#include "core/RessourceLoader.h"

std::map<std::string, sf::Texture> RessourceLoader::texturesMap;


RessourceLoader::RessourceLoader(sf::Font font, sf::Clock clock,
                                int height, int width, float gameSpeed )
    : p_GameFont(font),         
      p_GameClock(clock),
      p_GameWindow( sf::RenderWindow(sf::VideoMode({static_cast<unsigned int>(width), static_cast<unsigned int>(height)}), "Survivor !"))
{

    sf::Texture placeholder;
    if (!placeholder.loadFromFile("assets/texture/placeholder.png")) {
        throw std::runtime_error("Unable to charge texture placeholder.");
    }
    texturesMap.insert({"__placeholder__", placeholder});
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
    auto it = texturesMap.find(name);
    if (it != texturesMap.end()) {
        return it->second;
    }

    //return placeholder if texture not exists
    return texturesMap.at("__placeholder__");
}

void RessourceLoader::addTexture(const std::string & nameFile, const std::string & path) {

    //to prevent adding multiple textures with the same name
     if (texturesMap.find(nameFile) != texturesMap.end()) {
        return;
    }

    sf::Texture t(path);
    texturesMap.insert({nameFile,t});
}


