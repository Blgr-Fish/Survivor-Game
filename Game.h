#pragma once
#include "RessourceLoader.h"


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

private:

    const int SCREEN_WIDTH = 1260;
    const int SCREEN_HEIGHT = 720;
    const float GAME_SPEED = 0.1; //0.1s frame

    RessourceLoader  p_ressourceLoader ;


};