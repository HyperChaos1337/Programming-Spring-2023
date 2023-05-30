#include "BGFile.h"

void BGFile::set_filename(const std::string &name){
    this->filename = name;
}

std::string BGFile::get_filename(){
    return filename;
}