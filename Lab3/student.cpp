#include "student.h"

using std::bitset;

Student::Student(const string& surname, const string& name,
    const string& patronymic, Gender gender) :
    surname(surname), name(name),
    patronymic(patronymic), gender(gender) {}
Student::Student(const string& surname, const string& name,
    const string& patronymic, int gender) :
    surname(surname), name(name), patronymic(patronymic) {
    if (gender == 0) this->gender = man;
    else this->gender = woman;
}
Student::Student() {}

void Student::set_name(const string& name) {
    this->name = name;
}
void Student::set_surname(const string& surname) {
    this->surname = surname;
}
void Student::set_patronymic(const string& patronymic) {
    this->patronymic = patronymic;
}
void Student::set_gender(Gender gender) {
    this->gender = gender;
}

const string & Student::get_name() const {
    return name;
}
const string & Student::get_surname() const {
    return surname;
}
const string & Student::get_patronymic() const {
    return patronymic;
}
Gender Student::get_gender() const {
    return gender;
}

void Student::write(ofstream& output) {
    output << bitset<8>(IDENTITY_STUDENT) << ' ' << '\n';
    write_in_file(output, name);
    write_in_file(output, surname);
    write_in_file(output, patronymic);
    output << bitset<8>(gender) << ' ' << '\n';
}