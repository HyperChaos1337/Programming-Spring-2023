#include "cell.h"

Cell::Cell(int size): size(size){}

void Cell::set_size(int cell_size){
    this->size = cell_size;
}

int Cell::get_size()const{
    return size;
}