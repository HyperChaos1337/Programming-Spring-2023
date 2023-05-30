#ifndef TESTCW_LEVELFILE_H
#define TESTCW_LEVELFILE_H

#include "File.h"

class LevelFile: public File{
private:
    std::string filename;
public:
    void set_filename(const std::string& name) override;
    std::string get_filename() override;
};

#endif