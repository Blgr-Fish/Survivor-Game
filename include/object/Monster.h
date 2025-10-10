#include "object/Player.h"

class Monster : public LivingObject2D {
    public:
        Monster(int x , int y,int speed, int health, std::string spriteName, RessourceLoader &ressourceLoader, Player &player) :
        LivingObject2D(x,y,speed,health,spriteName,ressourceLoader) {

            this->player = &player;
        }

        // used to find the player in order to track him
        const Player & getPlayer() const { return *this->player ;}


    protected:
    Player* player;
};