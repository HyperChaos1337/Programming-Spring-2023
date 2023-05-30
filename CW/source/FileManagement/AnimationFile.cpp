#include "AnimationFile.h"

void AnimationFile::set_filename(const std::string &name){
    this->filename = name;
}

std::string AnimationFile::get_filename(){
    return filename;
}