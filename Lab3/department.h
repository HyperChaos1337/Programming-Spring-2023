#pragma once

#include <string>
#include "group.h"

class Department{
private:
    string title;
    vector<Group> department;
public:

    Department(const string& title);
    Department();

    void set_title(const string& title);
    void set_department(vector<Group>& department);

    const string & get_title() const;
    vector<Group>& get_department();

    void add_group();
    bool delete_group(int data);
    Group* find_group(int data);
    void delete_all();

    void write(std::ofstream& output);

};