#include "PlayerFile.h"

void PlayerFile::set_filename(const std::string &name){
    this->filename = name;
}

std::string PlayerFile::get_filename(){
    return filename;
}
