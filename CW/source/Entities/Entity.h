#ifndef TESTCW_ENTITY_H
#define TESTCW_ENTITY_H

#include <SFML/Graphics.hpp>
#include <vector>
#include "../Animation/AnimationManager.h"
#include "../Game/Level.h"


using namespace sf;

class Entity{
public:

    float x,y,dx,dy,w,h;
    AnimationManager anim;
    std::vector<Object> obj;
    bool life, dir;
    float timer, timer_end;
    std::string Name;
    int Health;

public:

    Entity(AnimationManager &A,int X, int Y);
    virtual void update(float time) = 0;
    void draw(RenderWindow &window);
    FloatRect getRect();
    void option(std::string NAME, float SPEED=0, int HEALTH=10, std::string FIRST_ANIM="");

};

#endif