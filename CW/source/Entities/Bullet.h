#ifndef TESTCW_BULLET_H
#define TESTCW_BULLET_H

#include "Entity.h"

class Bullet: public Entity{
public:

    Bullet(AnimationManager &a, Level &lev,int x,int y,bool dir);
    void update(float time) override;

};

#endif