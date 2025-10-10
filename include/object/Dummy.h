#include "object/Monster.h"

class Dummy : public Monster {

    public:
        Dummy(int x, int y,RessourceLoader & ressourceLoader ,Player & player);

        
        void move() override ;
        void update() override ; 

    private:


};