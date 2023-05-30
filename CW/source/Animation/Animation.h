#ifndef TESTCW_ANIMATION_H
#define TESTCW_ANIMATION_H

#include "TinyXML/tinyxml.h"
#include <SFML/Graphics.hpp>

using namespace sf;

class Animation{
public:
    std::vector<IntRect> frames, frames_flip;
    float currentFrame, speed;
    bool loop, flip, isPlaying;   // Loop показывает зациклена ли анимация. Например, анимация взрыва должна проиграться один раз и остановиться, loop=false
    Sprite sprite;
public:
    Animation();
    void tick(float time);
};

#endif