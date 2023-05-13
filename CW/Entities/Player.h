#ifndef COURSE_WORK_2_PLAYER_H
#define COURSE_WORK_2_PLAYER_H

#include "SFML/Graphics.hpp"

using namespace sf;

class Player{
public:
    float dx, dy;
    FloatRect rect;
    Sprite sprite;
    float frame;
public:
    Player() = default;
    Player(Texture& image);
    void update(float time);
};

#endif