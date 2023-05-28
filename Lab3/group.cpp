#include "group.h"

using std::bitset;

Group::Group(int number):number(number){}
Group::Group(){}

void Group::set_number(int number){
    this->number = number;
}
void Group::set_group(vector<Student> &group){
    this->group = group;
}

int Group::get_number() const {
    return number;
}
vector<Student>& Group::get_group(){
    return group;
}

void Group::add_student(){
    Student s;
    char permission;
    s.set_name(validate_string("Enter name", true));
    s.set_surname(validate_string("Enter surname", true));
    s.set_patronymic(validate_string("Enter patronymic", false));
    info("Man or woman?(1/2)");
    choice(permission);
    if (permission == '1') s.set_gender(man);
    else s.set_gender(woman);
    group.push_back(s);
}
bool Group::delete_student(const string &data){
    int index = -1;
    Student s;
    for (int i = 0; i < group.size(); ++i) {
        s = group.at(i);
        if (s.get_surname() == data) {
            index = i;
            break;
        }
    }
    if (index != -1) {
        group.erase(group.begin() + index);
        return true;
    } else error("Student not found");
    return false;
}
Student* Group::find_student(const string &data){
    for (Student &s: group) {
        if (s.get_surname() == data)
            return &s;
    }
    error("Student not found");
    return nullptr;
}
void Group::delete_all() {
    group.clear();
}

void Group::write(std::ofstream &output){
    output << bitset<8>(IDENTITY_GROUP) << ' ' << std::endl;
    output << bitset<16>(number) << ' ' << std::endl;
    for (Student &student: group)
        student.write(output);
}