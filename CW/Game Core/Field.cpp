#include "Field.h"

Field::Field(int height, int width){
    this->height = DEFAULT_HEIGHT;
    this->width = DEFAULT_WIDTH;
}

int Field::get_width() const{
    return width;
}
int Field::get_height() const{
    return height;
}