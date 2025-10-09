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

    Player player(100, "null",p_ressourceLoader);
    player.setPosition(360,360);
    player.setCameraSize(SCREEN_WIDTH,SCREEN_HEIGHT);


    sf::Sprite background = setupBackground();

    

    
        


    // Boucle principale
    while ( window.isOpen()) {
        std::optional<sf::Event> event;
        while ((event = (window.pollEvent()))) {

            if (event.has_value() && event->is<sf::Event::Closed>())
                window.close();
        }

        
        if (p_ressourceLoader.getClock().getElapsedTime().asSeconds() > GAME_SPEED) {
                window.setView(player.getCamera());
                player.update();
                p_ressourceLoader.getClock().restart();
            }
        
        window.clear(sf::Color::Black); // clear screen 
        window.draw(background);
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