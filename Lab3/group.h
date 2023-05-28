#pragma once

#include "student.h"
#include "message_box.h"
#include "validator.h"
#include <vector>

using std::vector;
using std::string;

class Group {
private:
	int number;
	vector<Student> group;
public:

	Group(int number);
	Group();

	void set_number(int number);
	void set_group(vector<Student>& group);

	int get_number() const;
	vector<Student>& get_group();

	void add_student();
	bool delete_student(const string& data);
	Student* find_student(const string& data);
	void delete_all();

	void write(ofstream& output);

};