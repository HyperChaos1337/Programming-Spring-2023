#ifndef TESTCW_STAR_H
#define TESTCW_STAR_H

#include "Entity.h"

class Star: public Entity{
public:
    Star(AnimationManager &a,Level &lev,int x,int y):Entity(a,x,y)
    {
        option("Star", 0, 1, "stay");
    }
    void update(float time) override;
};

#endif