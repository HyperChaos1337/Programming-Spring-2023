#ifndef PR_LAB2_FILE_WORK_H
#define PR_LAB2_FILE_WORK_H

#include "file_input.h"

#include <cmath>

class FileWork{
public:
    FileInput fileInput;
    std::string lcs = "";
public:
    std::string LCS(std::string s1, std::string s2, int m, int n);
    void highlight(std::string text, std::string pattern);
    void print_match(char temp);
    void print_mismatch(char temp);
    void set_std_parameters();
};

#endif