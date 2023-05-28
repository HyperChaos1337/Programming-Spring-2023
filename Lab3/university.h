#pragma once

#include "faculty.h"
#include <string>

class University{
private:
    string title;
    vector<Faculty> university;
public:

    University(const string& title);
    University();

    void set_title(const string& title);
    void set_university(vector<Faculty>& university);

    const string& get_title();
    vector<Faculty>& get_university();

    void add_faculty();
    bool delete_faculty(const string& data);
    Faculty* find_faculty(const string& data);
    void delete_all();

    vector<string> find_student(int mode);

    void write(bool is_safe);
    bool read(bool is_safe);

};