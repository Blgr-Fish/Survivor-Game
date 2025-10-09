#include "core/Game.h"
#include "core/RessourceLoader.h"
#include "object/LivingObject2D.h"
#include "object/Player.h"
#include <iostream>


Game::Game() :p_ressourceLoader(sf::Font("assets/font/pixelmix.ttf"),
                                sf::Clock(),
                                SCREEN_HEIGHT,
                                SCREEN_WIDTH,
                                GAME_SPEED)
{
 
    p_ressourceLoader.addTexture("missing","assets/texture/missing.png");
}  
    

Game::~Game() {
}




void Game::GameLaunch() {


    sf::RenderWindow  & window = p_ressourceLoader.getRenderWindow() ;

    auto playerPtr = std::make_unique<Player>(100, "null",p_ressourceLoader);
    Player* playerAcess = playerPtr.get();
    addObject(std::move(playerPtr));

    playerAcess->setPosition(SCREEN_WIDTH/2,SCREEN_HEIGHT/2);
    playerAcess->setCameraSize(SCREEN_WIDTH,SCREEN_HEIGHT);

    sf::Sprite background = setupBackground();

    

    
        


    // Boucle principale
    while ( window.isOpen()) {
        std::optional<sf::Event> event;
        while ((event = (window.pollEvent()))) {

            if (event.has_value() && event->is<sf::Event::Closed>())
                window.close();
        }

        
        
        
        window.clear(sf::Color::Black); // clear screen 
         if (p_ressourceLoader.getClock().getElapsedTime().asSeconds() > GAME_SPEED) {
                window.draw(background);
                updateObjects(window);
                window.display();
                p_ressourceLoader.getClock().restart();
            }
        
    }
    
}

void Game::addObject(std::unique_ptr<Object2D> obj) {
    objectsList.push_back(std::move(obj));
}

void Game::updateObjects(sf::RenderWindow & window) {
    for (auto it = objectsList.begin(); it != objectsList.end(); ) {
        
        if (auto living = dynamic_cast<LivingObject2D*>(it->get())) {
            //LivingObjects
            if (!living->checkIsAlive()) {
                it = objectsList.erase(it);
                continue;
            } else { 
                //Player
                if (auto player = dynamic_cast<Player*>(it->get())) {
                    window.setView(player->getCamera());
                } 
                living->update();
                window.draw(living->getSpriteObject().getSprite());
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

sf::Sprite Game::setupBackground() {
    
    sf::Texture & t((p_ressourceLoader.getTexture("missing")));
    t.setRepeated(true);
    t.setSmooth(false);

    sf::Sprite s(t);


        
    int scaleFactor = t.getSize().x / 32; // 256 / 32 = 8
    s.setScale(sf::Vector2f{1.f / scaleFactor, 1.f / scaleFactor});

    // on définit le rect à une taille plus grande → la texture se répète
    s.setTextureRect(sf::IntRect({0, 0}, {SCREEN_WIDTH * scaleFactor,
    SCREEN_HEIGHT * scaleFactor}));

    return s ;
}