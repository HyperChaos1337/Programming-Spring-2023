#pragma once

#include <string>
#include "department.h"

class Faculty{
private:
    string title;
    vector<Department> faculty;
public:

    Faculty(const string& title);
    Faculty();

    void set_title(const string& title);
    void set_faculty(vector<Department>& faculty);

    const string & get_title() const;
    vector<Department>& get_faculty();

    void add_department();
    bool delete_department(const string& data);
    Department* find_department(const string& data);
    void delete_all();

    void write(std::ofstream& output);

};