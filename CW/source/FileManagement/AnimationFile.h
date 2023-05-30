#ifndef TESTCW_ANIMATIONFILE_H
#define TESTCW_ANIMATIONFILE_H

#include "File.h"

class AnimationFile: public File{
private:
    std::string filename;
public:
    void set_filename(const std::string& name) override;
    std::string get_filename() override;
};

#endif