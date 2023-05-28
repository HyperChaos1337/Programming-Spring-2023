#pragma once

#include "file_read.h"
#include "predefinitions.h"
#include <fstream>
#include <string>

using std::string;
using std::ofstream;

enum Gender {
	man = 0, woman = 1
};

class Student {
private:
	string name;
	string surname;
	string patronymic;
	Gender gender;
public:

	Student(const string& surname, const string& name,
		const string& patronymic, Gender gender);
	Student(const string& surname, const string& name,
		const string& patronymic, int gender);
	Student();

	void set_name(const string& name);
	void set_surname(const string& surname);
	void set_patronymic(const string& patronymic);
	void set_gender(Gender gender);

	void write(ofstream& output);

	const string & get_name() const;
	const string & get_surname() const;
	const string & get_patronymic() const;
	Gender get_gender() const;
};
