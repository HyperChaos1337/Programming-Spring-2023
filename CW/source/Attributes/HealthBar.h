#ifndef TESTCW_HEALTHBAR_H
#define TESTCW_HEALTHBAR_H

#include <SFML/Graphics.hpp>

using namespace sf;

class HealthBar{

public:
    Texture t;
    Sprite s;
    int max;
    RectangleShape bar;
public:
    HealthBar();
    void update(int k);
    void draw(RenderWindow &window);

};

#endif