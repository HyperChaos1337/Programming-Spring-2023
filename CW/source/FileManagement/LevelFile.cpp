#include "LevelFile.h"

void LevelFile::set_filename(const std::string &name){
    this->filename = name;
}

std::string LevelFile::get_filename(){
    return filename;
}