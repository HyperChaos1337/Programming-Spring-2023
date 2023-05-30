#ifndef TESTCW_PLAYER_H
#define TESTCW_PLAYER_H

#include "Entity.h"

class Player: public Entity
{
public:
    enum {stay,walk,duck,jump,climb} STATE;
    bool onLadder, shoot, hit;
    std::map<std::string,bool> key;
public:
    Player(AnimationManager &a, Level &lev,int x,int y);
    void Keyboard();
    void Animation(float time);
    void update(float time) override;
    void Collision(int num);

};

#endif