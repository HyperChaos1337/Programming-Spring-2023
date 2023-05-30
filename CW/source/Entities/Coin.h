#ifndef TESTCW_COIN_H
#define TESTCW_COIN_H

#include "Entity.h"

class Coin: public Entity{
public:
    Coin(AnimationManager &a, Level &lev,int x,int y): Entity(a,x,y){
        option("Coin", 0, 1, "stay");
    }
    void update(float time) override;

};

#endif