#ifndef COURSE_WORK_2_FIELD_H
#define COURSE_WORK_2_FIELD_H

#define DEFAULT_WIDTH 32
#define DEFAULT_HEIGHT 24

#include "cell.h"
#include "SFML/Graphics.hpp"

#include <iostream>

using namespace sf;

class Field{
private:
    int height, width;
public:
    Field() = default;
    Field(int height, int width);
    String* get_tile();
    void set_height(int height);
    void set_width(int width);
    int get_height() const;
    int get_width() const;
    void fill();
    void print();
};

#endif