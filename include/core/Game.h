#pragma once
#include "core/RessourceLoader.h"
#include "object/Object2D.h"
#include <memory>
#include <vector>



class Game {
public:
    Game() ;
    ~Game();
     
     
    void GameLaunch();

    void setTexts();

    void restartGame();

    int getScreenWidth() const ;
    int getScreenHeight() const ;
    float getGameSpeed() const ;

    void addObject(std::unique_ptr<Object2D> obj);
    void removeObject() ;

private:

    const int SCREEN_WIDTH = 1260;
    const int SCREEN_HEIGHT = 720;
    const float GAME_SPEED = 0.1; //0.1s frame

    RessourceLoader  p_ressourceLoader ;

    std::vector<std::unique_ptr<Object2D>> objectsList ;


};