#ifndef TESTCW_MUSICFILE_H
#define TESTCW_MUSICFILE_H

#include "File.h"

class MusicFile: public File{
private:
    std::string filename;
public:
    void set_filename(const std::string& name) override;
    std::string get_filename() override;
};

#endif