#pragma once
#include <SFML/Graphics.hpp>
#include <map>



class RessourceLoader {
    public:

        RessourceLoader(sf::Font font, sf::Clock clock,
                        int height, int width, float gameSpeed);

        const sf::Font & getFont() const ;
        sf::Clock & getClock();
        sf::RenderWindow & getRenderWindow(); 

        sf::Texture& getTexture(const std::string& name);

        void addTexture( const std::string & name);


        


    private:

        sf::Font p_GameFont;
        sf::Clock p_GameClock ;
        sf::RenderWindow p_GameWindow ;
        
        static std::map<std::string, sf::Texture> texturesMap;
        
};