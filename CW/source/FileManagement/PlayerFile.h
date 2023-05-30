#ifndef TESTCW_PLAYERFILE_H
#define TESTCW_PLAYERFILE_H

#include "File.h"

class PlayerFile: public File{
private:
    std::string filename;
public:
    void set_filename(const std::string& name) override;
    std::string get_filename() override;
};

#endif