#pragma once
#include <SFML/Graphics.hpp>



class RessourceLoader {
    public:

        RessourceLoader(sf::Font font, sf::Clock clock,
                        int height, int width, float gameSpeed);

        const sf::Font & getFont() const ;
        sf::Clock & getClock();
        sf::RenderWindow & getRenderWindow(); 

        


    private:

        sf::Font p_GameFont;
        sf::Clock p_GameClock ;
      
            
       
        sf::RenderWindow p_GameWindow ;

        
};