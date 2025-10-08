#include "core/Game.h"
#include "core/RessourceLoader.h"
#include "object/LivingObject2D.h"
#include "object/Player.h"


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

    Player player(100, "null",p_ressourceLoader);
    player.setPosition(360,360);
    


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
        window.draw(player.getSpriteObject().getSprite());
        window.display();
    }
    
}

void Game::addObject(std::unique_ptr<Object2D> obj) {
    objectsList.push_back(std::move(obj));
}

void Game::removeObject() {
    for (auto it = objectsList.begin(); it != objectsList.end(); ) {
        
        if (auto living = dynamic_cast<LivingObject2D*>(it->get())) {
            if (!living->checkIsAlive()) {
                it = objectsList.erase(it);
                continue;
            }
        }
        ++it;
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