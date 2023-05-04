#include "department.h"

Department::Department(const string& title): title(title){}
Department::Department(){}

void Department::set_title(const std::string &title){
    this->title = title;
}
void Department::set_department(vector<Group> &department){
    this->department = department;
}

const string & Department::get_title() const {
    return title;
}

vector<Group>& Department::get_department(){
    return department;
}

void Department::add_group(){
    Group group;
    char permission;
    info("Enter group number");
    group.set_number(validate_argument(0, 10000));
    info("Want to add students now?\n1 - Yes\n2 - No");
    choice(permission);
    if (permission == '1') {
        info("Enter number of students to add");
        int quantity = validation();
        for (int i = 0; i < quantity; ++i) {
            group.add_student();
        }
    }
    department.push_back(group);
}
bool Department::delete_group(int data) {
    int index = -1;
    Group g;
    for (int i = 0; i < department.size(); ++i) {
        g = department.at(i);
        if (g.get_number() == data) {
            g.delete_all();
            index = i;
            break;
        }
    }
    if (index != -1) {
        department.erase(department.begin() + index);
        return true;
    } else error("Group not found");
    return false;
}
Group* Department::find_group(int data){
    for (Group &g: department) {
        if (g.get_number() == data)
            return &g;
    }
    error("Group not found");
    return nullptr;
}
void Department::delete_all(){
    for (Group g: department) {
        g.delete_all();
    }
    department.clear();
}

void Department::write(std::ofstream &output){
    output << std::bitset<8>(IDENTITY_DEPARTMENT) << ' ' << std::endl;
    write_in_file(output, title);
    for (Group &group: department)
        group.write(output);
}