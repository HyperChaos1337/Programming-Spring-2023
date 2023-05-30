#include "MusicFile.h"

void MusicFile::set_filename(const std::string &name){
    this->filename = name;
}

std::string MusicFile::get_filename(){
    return filename;
}