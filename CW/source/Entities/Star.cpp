#include "Star.h"

void Star::update(float time){
    if (Health<=0) life=false;
    anim.tick(time);
}