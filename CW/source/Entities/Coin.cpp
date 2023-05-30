#include "Coin.h"

void Coin::update(float time){

    if (Health<=0) life=false;
    anim.tick(time);
}