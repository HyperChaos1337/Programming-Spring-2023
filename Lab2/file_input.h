#ifndef PR_LAB2_FILE_INPUT_H
#define PR_LAB2_FILE_INPUT_H

#include <fstream>
#include <iostream>
#include <cstring>
#include <windows.h>

class FileInput{
public:
    std::string str1 = "", str2 = "";
    std::ifstream file1, file2;
public:
   bool read_files(char* path1, char* path2);
   bool correct_extension(char* path);
   void error_msg_color();
   void warning_msg_color();
   void clean_color();
};

#endif