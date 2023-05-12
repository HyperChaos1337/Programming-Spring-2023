#ifndef COURSE_WORK_2_DISPLAY_H
#define COURSE_WORK_2_DISPLAY_H

#include "SFML/Graphics.hpp"
#include "GameCore/cell.h"

#include <iostream>
#include <algorithm>

using namespace sf;

class Display{
private:
    int H, W;
public:
    Cell cell;
    Display() = default;
    void show_display();

};

#endif