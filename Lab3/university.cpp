#include "university.h"
#include <iostream>


University::University(const string& title): title(title){}
University::University(){}

void University::set_title(const string &title){
    this->title = title;
}
void University::set_university(vector<Faculty> &university){
    this->university = university;
}

const string& University::get_title(){
    return title;
}
vector<Faculty>& University::get_university(){
    return university;
}

void University::add_faculty(){
    Faculty faculty;
    char permission;
    faculty.set_title(validate_string("Enter faculty name", true));
    info("Want to add departments now?\n1 - Yes\n2 - No");
    choice(permission);
    if (permission == '1') {
        info("Enter number of departments to create");
        int quantity = validation();
        for (int i = 0; i < quantity; ++i) {
            faculty.add_department();
        }
    }
    university.push_back(faculty);
}
bool University::delete_faculty(const string &data) {
    int index = -1;
    Faculty f;
    for (int i = 0; i < university.size(); ++i) {
        f = university.at(i);
        if (f.get_title() == data) {
            f.delete_all();
            index = i;
            break;
        }
    }
    if (index != -1) {
        university.erase(university.begin() + index);
        return true;
    } else error("Faculty not found");
    return false;
}
Faculty* University::find_faculty(const string &data){
    for (Faculty &f: university) {
        if (f.get_title() == data)
            return &f;
    }
    error("Faculty not found");
    return nullptr;
}
void University::delete_all(){
    for (Faculty f: university) {
        f.delete_all();
    }
    university.clear();
}

vector<string> University::find_student(int mode){
    vector<std::string> students;
    string gender;
    switch (mode) {
        case 0: {
            std::string surname = validate_string("Enter surname", false);
            for (Faculty &f: university)
                for (Department &d: f.get_faculty())
                    for (Group &g: d.get_department())
                        for (Student &s: g.get_group())
                            if (s.get_surname() == surname) {
                                gender = (s.get_gender() == man) ? " - man" : " - woman";
                                students.push_back(
                                        s.get_name() + " " + s.get_surname() + " " + s.get_patronymic() + gender + " "
                                        + std::to_string(g.get_number()) + " " + d.get_title() + " " + f.get_title());
                            }
        }
            break;
        case 1: {
            std::string name = validate_string("Enter name", false);
            for (Faculty &f: university)
                for (Department &d: f.get_faculty())
                    for (Group &g: d.get_department())
                        for (Student &s: g.get_group())
                            if (s.get_name() == name) {
                                gender = (s.get_gender() == man) ? " - man" : " - woman";
                                students.push_back(
                                        s.get_name() + " " + s.get_surname() + " " + s.get_patronymic() + gender + " "
                                        + std::to_string(g.get_number()) + " " + d.get_title() + " " + f.get_title());
                            }
        }
            break;
        case 2: {
            std::string patronymic = validate_string("Enter patronymic", false);
            for (Faculty &f: university)
                for (Department &d: f.get_faculty())
                    for (Group &g: d.get_department())
                        for (Student &s: g.get_group())
                            if (s.get_patronymic() == patronymic) {
                                gender = (s.get_gender() == man) ? " - man" : " - woman";
                                students.push_back(
                                        s.get_name() + " " + s.get_surname() + " " + s.get_patronymic() + gender + " "
                                        + std::to_string(g.get_number()) + " " + d.get_title() + " " + f.get_title());
                            }
        }
            break;
        case 3 : {
            Gender gen;
            char permission;
            info("Man or woman?(1/2)");
            choice(permission);
            if (permission == '1') gen = man;
            else gen = woman;
            for (Faculty &f: university)
                for (Department &d: f.get_faculty())
                    for (Group &g: d.get_department())
                        for (Student &s: g.get_group())
                            if (s.get_gender() == gen) {
                                gender = (s.get_gender() == man) ? " - man" : " - woman";
                                students.push_back(
                                        s.get_name() + " " + s.get_surname() + " " + s.get_patronymic() + gender + " "
                                        + std::to_string(g.get_number()) + " " + d.get_title() + " " + f.get_title());
                            }
        }
            break;
    }
    return students;
}

void University::write(bool is_safe){
    std::string path;
    if (!is_safe) path = "C:/Users/User/CLionProjects/PR_Lab3_V6/database.bin";
    else path = "C:/Users/User/CLionProjects/PR_Lab3_V6/cmake-build-debug/database.bin";
    std::ofstream out(path, std::ios_base::binary | std::ios_base::out);
    out << std::bitset<8>((int) 'U') << ' ' << std::endl;
    write_in_file(out, title);
    for (Faculty &faculty: university)
        faculty.write(out);
    out.close();
}

bool University::read(bool is_safe){
    std::string path;
    if (!is_safe) {
        path = "C:/Users/User/CLionProjects/PR_Lab3_V6/database.bin";
        write(true);
    } else path = "C:/Users/User/CLionProjects/PR_Lab3_V6/cmake-build-debug/database.bin";
    std::ifstream in(
            path,
            std::ios_base::binary | std::ios_base::in);
    try {
        if (check_key(in, 'U')) {
            delete_all();
            title = read_from_file(in);
            char status;
            Faculty *nowF = nullptr;
            Department *nowD = nullptr;
            Group *nowG = nullptr;
            bool notMistake = true, mistake = false;
            while (!in.eof()) {
                status = read_key(in);
                if (status == 0) break;
                if (mistake) {
                    std::cout << 1;
                    notMistake = false;
                }
                if (notMistake) {
                    switch (status) {
                        case 'F': {
                            Faculty faculty(read_from_file(in));
                            university.push_back(faculty);
                            nowF = &university.at(university.size() - 1);
                        }
                            break;
                        case 'D': {
                            Department department(read_from_file(in));
                            if (nowF != nullptr) {
                                nowF->get_faculty().push_back(department);
                                nowD = &nowF->get_faculty().at(nowF->get_faculty().size() - 1);
                            } else mistake = true;
                        }
                            break;
                        case 'G': {
                            Group group(read_int(in));
                            if (nowD != nullptr) {
                                nowD->get_department().push_back(group);
                                nowG = &nowD->get_department().at(nowD->get_department().size() - 1);
                            } else mistake = true;
                        }
                            break;
                        case 'S': {
                            Student student;
                            student.set_name(read_from_file(in));
                            student.set_surname(read_from_file(in));
                            student.set_patronymic(read_from_file(in));
                            if (read_int(in) == 0) student.set_gender(man);
                            else student.set_gender(woman);
                            if (nowG != nullptr) {
                                nowG->get_group().push_back(student);
                            } else mistake = true;
                        }
                            break;
                    }
                } else {
                    error("Data have wrong format");
                    in.close();
                    read(true);
                    return false;
                }
            }
        } else {
            error("Data have wrong format");
            in.close();
            read(true);
            return false;
        }
        in.close();
        return true;
    }
    catch (std::invalid_argument exception) {
        error("Data have wrong format");
        read(true);
        return false;
    }
}