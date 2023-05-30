#ifndef TESTCW_BGFILE_H
#define TESTCW_BGFILE_H

#include "File.h"

class BGFile: public File{
private:
    std::string filename;
public:
    void set_filename(const std::string& name) override;
    std::string get_filename() override;
};

#endif