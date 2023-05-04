#include "faculty.h"

Faculty::Faculty(const string& title):title(title){}
Faculty::Faculty(){}

void Faculty::set_title(const string &title){
    this->title = title;
}
void Faculty::set_faculty(vector<Department> &faculty){
    this->faculty = faculty;
}

const string & Faculty::get_title() const {
    return title;
}
vector<Department>& Faculty::get_faculty(){
    return faculty;
}

void Faculty::add_department(){
    Department department;
    char permission;
    department.set_title(validate_string("Enter department name", true));
    info("Want to add groups now?\n1 - Yes\n2 - No");
    choice(permission);
    if (permission == '1') {
        info("Enter number of groups to create");
        int quantity = validation();
        for (int i = 0; i < quantity; ++i) {
            department.add_group();
        }
    }
    faculty.push_back(department);
}
bool Faculty::delete_department(const string &data){
    int index = -1;
    Department d;
    for (int i = 0; i < faculty.size(); ++i) {
        d = faculty.at(i);
        if (d.get_title() == data) {
            d.delete_all();
            index = i;
            break;
        }
    }
    if (index != -1) {
        faculty.erase(faculty.begin() + index);
        return true;
    } else error("Department not found");
    return false;
}
Department* Faculty::find_department(const string &data){
    for (Department &d: faculty) {
        if (d.get_title() == data)
            return &d;
    }
    error("Department not found");
    return nullptr;
}
void Faculty::delete_all(){
    for (Department d: faculty) {
        d.delete_all();
    }
    faculty.clear();
}

void Faculty::write(std::ofstream &output) {
    output << std::bitset<8>(IDENTITY_FACULTY) << ' ' << std::endl;
    write_in_file(output, title);
    for (Department &department: faculty)
        department.write(output);
}