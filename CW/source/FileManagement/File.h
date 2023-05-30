#ifndef TESTCW_FILE_H
#define TESTCW_FILE_H

#include <string>

class File{
public:
    virtual void set_filename(const std::string& name) = 0;
    virtual std::string get_filename() = 0;
};

#endif