#include "core/Game.h"
#include "core/RessourceLoader.h"

Game::Game() :p_ressourceLoader(sf::Font("assets/font/pixelmix.ttf"),
                                sf::Clock(),
                                SCREEN_HEIGHT,
                                SCREEN_WIDTH,
                                GAME_SPEED)
{
   
}  
    

Game::~Game() {
}




void Game::GameLaunch() {


    sf::RenderWindow  & window = p_ressourceLoader.getRenderWindow() ;

    


    // Boucle principale
    while ( window.isOpen()) {
        std::optional<sf::Event> event;
        while ((event = (window.pollEvent()))) {

            if (event.has_value() && event->is<sf::Event::Closed>())
                window.close();
        }

        /*
        if (p_clock.getElapsedTime().asSeconds() > GAME_SPEED) {
                
                p_clock.restart();
            }
        */
        window.clear(sf::Color::Black); // clear screen 
        window.display();
    }
    
}

void Game::restartGame() {
}

 int Game::getScreenWidth() const {
    return SCREEN_WIDTH;
}

 int Game::getScreenHeight() const {
    return SCREEN_HEIGHT;
}

 float Game::getGameSpeed() const {
    return GAME_SPEED;
}