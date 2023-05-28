#include "Interface.h"
#include <conio.h>
#include <iostream>
#include "predefinitions.h"
#include "message_box.h"
#include "validator.h"

void Interface::students_menu(vector<std::string> students){
    std::cout << "Student found: " << std::endl;
    if (!students.empty())
        for (const std::string &student: students) {
            std::cout << student
                      << std::endl;
        }
    else error("There's no one here...");
}

void Interface::university_menu(int pos, University &university){
    system("cls");
    bool flag = false;
    printf("Select option:\n");
    printf("1.Add faculty%s\n", pos == 1 ? " <--" : " ");
    printf("2.Remove faculty%s\n", pos == 2 ? " <--" : " ");
    printf("3.Rename university%s\n", pos == 3 ? " <--" : " ");
    printf("4.Edit faculty information%s\n", pos == 4 ? " <--" : " ");
    printf("5.Find student(-s)%s\n", pos == 5 ? " <--" : " ");
    printf("6.Save data%s\n", pos == 6 ? " <--" : " ");
    printf("7.Load data%s\n", pos == 7 ? " <--" : " ");
    printf("8.Exit%s\n", pos == 8 ? " <--" : " ");
    std::cout << "University: " << university.get_title() << std::endl;
    std::cout << "Faculties: ";
    if (university.get_university().empty()) std::cout << std::endl;
    else
        for (const Faculty &faculty: university.get_university()) {
            std::cout << faculty.get_title() << " ";
            flag = true;
        }
    if (flag)std::cout << std::endl;
}
void Interface::university_interface(University &university){
    bool exitFlag = false, permissionFlag;
    short symbol;
    short position = 1;
    char YN;
    university_menu(position, university);
    std::string title;
    while (!exitFlag) {
        permissionFlag = false;
        symbol = (short) getch();
        if (symbol == FIRST_BYTE_ARROW) symbol = (short) getch();
        switch (symbol) {
            case ARROW_UP:
                if (0 != position - 1)
                    position--;
                else position = MAX_ARROW_POSITION_UNI_AND_STUD;
                break;
            case ARROW_DOWN:
                if (position < MAX_ARROW_POSITION_UNI_AND_STUD) position++;
                else
                    position = MIN_ARROW_POSITION;
                break;
            case W:
                if (0 != position - 1)
                    position--;
                else position = MAX_ARROW_POSITION_UNI_AND_STUD;
                break;
            case S:
                if (position < MAX_ARROW_POSITION_UNI_AND_STUD) position++;
                else
                    position = MIN_ARROW_POSITION;
                break;
            case ESC:
                exitFlag = true;
                break;
            case ENTER:
                permissionFlag = true;
                break;
            case ONE:
                position = 1;
                break;
            case TWO:
                position = 2;
                break;
            case THREE:
                position = 3;
                break;
            case FOUR:
                position = 4;
                break;
            case FIVE:
                position = 5;
                break;
            case SIX:
                position = 6;
                break;
            case SEVEN:
                position = 7;
                break;
            default:;
        }
        university_menu(position, university);
        switch (position) {
            case 1:
                if (permissionFlag) {
                    university.add_faculty();
                    university_menu(position, university);

                }
                break;
            case 2:
                if (permissionFlag) {
                    if (!university.get_university().empty()) {
                        if (university.delete_faculty(
                                validate_string("Enter faculty title", true)))
                            university_menu(position, university);
                    } else error("Faculties not found");
                }
                break;
            case 3:
                if (permissionFlag) {
                    std::cout << "Enter new title" << std::endl;
                    std::cin >> title;
                    if (title.empty()) error("Title cannot be empty");
                    else {
                        university.set_title(title);
                        university_menu(position, university);
                    }
                }
                break;
            case 4:
                if (permissionFlag) {
                    if (!university.get_university().empty()) {
                        Faculty *f = university.find_faculty(validate_string("Enter faculty title", true));
                        if (f != nullptr) {
                            faculty_menu(1, *f);
                            faculty_interface(*f, university);
                            university_menu(position, university);
                        }
                    } else error("Faculties not found");
                }
                break;
            case 5:
                if (permissionFlag) {
                    int mode;
                    std::cout << "Select search attribute(0 - Surname, 1 - Name, 2 - Patronymic, 3 - Gender)"
                              << std::endl;
                    mode = validate_argument(0, 3);
                    students_menu(university.find_student(mode));
                }
                break;
            case 6:
                if (permissionFlag) {
                    university.write(false);
                }
                break;
            case 7:
                if (permissionFlag) {
                    if (university.read(false)) {
                        university_menu(position, university);
                    }
                }
                break;
            case 8:
                if (permissionFlag) {
                    std::cout << "Save before exit?(1 - Yes, 2 - No)" << std::endl;
                    choice(YN);
                    if (YN == '1') {
                        university.write(false);
                    }
                    exit(0);
                }
                break;
            default:
                break;
        }
    }
}

void Interface::faculty_menu(int pos, Faculty &faculty){
    system("cls");
    bool flag = false;
    printf("Select option:\n");
    printf("1.Add department%s\n", pos == 1 ? " <--" : " ");
    printf("2.Delete department%s\n", pos == 2 ? " <--" : " ");
    printf("3.Rename faculty%s\n", pos == 3 ? " <--" : " ");
    printf("4.Edit department information%s\n", pos == 4 ? " <--" : " ");
    printf("5.Find student(-s)%s\n", pos == 5 ? " <--" : " ");
    printf("6.Save data%s\n", pos == 6 ? " <--" : " ");
    printf("7.Load data%s\n", pos == 7 ? " <--" : " ");
    printf("8.Return to university%s\n", pos == 8 ? " <--" : " ");
    printf("9.Exit%s\n", pos == 9 ? " <--" : " ");
    std::cout << "Faculty: " << faculty.get_title() << std::endl;
    std::cout << "Departments: ";
    if (faculty.get_faculty().empty()) std::cout << std::endl;
    else
        for (const Department &department: faculty.get_faculty()) {
            std::cout << department.get_title() << " ";
            flag = true;
        }
    if (flag)std::cout << std::endl;
}
void Interface::faculty_interface(Faculty &faculty, University &university){
    bool exitFlag = false, permissionFlag;
    short symbol;
    short position = 1;
    faculty_menu(position, faculty);
    char YN;
    std::string title;
    while (!exitFlag) {
        permissionFlag = false;
        symbol = (short) getch();
        if (symbol == FIRST_BYTE_ARROW) symbol = (short) getch();
        switch (symbol) {
            case ARROW_UP:
                if (0 != position - 1)
                    position--;
                else position = MAX_ARROW_POSITION;
                break;
            case ARROW_DOWN:
                if (position < MAX_ARROW_POSITION) position++;
                else
                    position = MIN_ARROW_POSITION;
                break;
            case W:
                if (0 != position - 1)
                    position--;
                else position = MAX_ARROW_POSITION;
                break;
            case S:
                if (position < MAX_ARROW_POSITION) position++;
                else
                    position = MIN_ARROW_POSITION;
                break;
            case ESC:
                exitFlag = true;
                break;
            case ENTER:
                permissionFlag = true;
                break;
            case ONE:
                position = 1;
                break;
            case TWO:
                position = 2;
                break;
            case THREE:
                position = 3;
                break;
            case FOUR:
                position = 4;
                break;
            case FIVE:
                position = 5;
                break;
            case SIX:
                position = 6;
                break;
            case SEVEN:
                position = 7;
                break;
            case EIGHT:
                position = 8;
                break;
            default:;
        }
        faculty_menu(position, faculty);
        switch (position) {
            case 1:
                if (permissionFlag) {
                    faculty.add_department();
                    faculty_menu(position, faculty);
                }
                break;
            case 2:
                if (permissionFlag) {
                    if (!faculty.get_faculty().empty()) {
                        if (faculty.delete_department(
                                validate_string("Enter department title", true)))
                            faculty_menu(position, faculty);
                    } else error("Department not found");
                }
                break;
            case 3:
                if (permissionFlag) {
                    std::cout << "Enter new title" << std::endl;
                    std::cin >> title;
                    if (title.empty()) error("Title cannot be empty");
                    else {
                        faculty.set_title(title);
                        faculty_menu(position, faculty);
                    }
                }
                break;
            case 4:
                if (permissionFlag) {
                    if (!faculty.get_faculty().empty()) {
                        Department *d = faculty.find_department(validate_string("Enter department title", true));
                        if (d != nullptr) {
                            department_interface(*d, university);
                            faculty_menu(position, faculty);
                        }
                    } else error("Department not found");
                }
                break;
            case 5:
                if (permissionFlag) {
                    int mode;
                    std::cout << "Select search attribute(0 - Surname, 1 - Name, 2 - Patronymic, 3 - Gender)"
                              << std::endl;
                    mode = validate_argument(0, 3);
                    students_menu(university.find_student(mode));
                }
                break;
            case 6:
                if (permissionFlag) {
                    university.write(false);
                }
                break;
            case 7:
                if (permissionFlag) {
                    if (university.read(false)) {
                        faculty_menu(position, faculty);
                    }
                }
                break;
            case 8:
                if (permissionFlag) {
                    university_menu(1, university);
                    return;
                }
                break;
            case 9:
                if (permissionFlag) {
                    std::cout << "Save before exit?(1 - Yes, 2 - No)" << std::endl;
                    choice(YN);
                    if (YN == '1') {
                        university.write(false);
                    }
                    exit(0);
                }
            default:
                break;
        }
    }
}

void Interface::department_menu(int pos, Department &department){
    system("cls");
    bool flag = false;
    printf("Select option\n");
    printf("1.Add group%s\n", pos == 1 ? " <--" : " ");
    printf("2.Remove group%s\n", pos == 2 ? " <--" : " ");
    printf("3.Rename department%s\n", pos == 3 ? " <--" : " ");
    printf("4.Edit group information%s\n", pos == 4 ? " <--" : " ");
    printf("5.Find students%s\n", pos == 5 ? " <--" : " ");
    printf("6.Save data%s\n", pos == 6 ? " <--" : " ");
    printf("7.Load data%s\n", pos == 7 ? " <--" : " ");
    printf("8.Return to faculty%s\n", pos == 8 ? " <--" : " ");
    printf("9.Exits%s\n", pos == 9 ? " <--" : " ");
    std::cout << "Department: " << department.get_title() << std::endl;
    std::cout << "Groups: ";
    if (department.get_department().empty()) std::cout << std::endl;
    else
        for (const Group &group: department.get_department()) {
            std::cout << group.get_number() << " ";
            flag = true;
        }
    if (flag)std::cout << std::endl;
}
void Interface::department_interface(Department &department, University &university){
    bool exitFlag = false, permissionFlag;
    short symbol;
    short position = 1;
    char YN;
    std::string title;
    department_menu(position, department);
    while (!exitFlag) {
        permissionFlag = false;
        symbol = (short) getch();
        if (symbol == FIRST_BYTE_ARROW) symbol = (short) getch();
        switch (symbol) {
            case ARROW_UP:
                if (0 != position - 1)
                    position--;
                else position = MAX_ARROW_POSITION;
                break;
            case ARROW_DOWN:
                if (position < MAX_ARROW_POSITION) position++;
                else
                    position = MIN_ARROW_POSITION;
                break;
            case W:
                if (0 != position - 1)
                    position--;
                else position = MAX_ARROW_POSITION;
                break;
            case S:
                if (position < MAX_ARROW_POSITION) position++;
                else
                    position = MIN_ARROW_POSITION;
                break;
            case ESC:
                exitFlag = true;
                break;
            case ENTER:
                permissionFlag = true;
                break;
            case ONE:
                position = 1;
                break;
            case TWO:
                position = 2;
                break;
            case THREE:
                position = 3;
                break;
            case FOUR:
                position = 4;
                break;
            case FIVE:
                position = 5;
                break;
            case SIX:
                position = 6;
                break;
            case SEVEN:
                position = 7;
                break;
            case EIGHT:
                position = 8;
                break;
            default:;
        }
        department_menu(position, department);
        switch (position) {
            case 1:
                if (permissionFlag) {
                    department.add_group();
                    department_menu(position, department);
                }
                break;
            case 2:
                if (permissionFlag) {
                    if (!department.get_department().empty()) {
                        std::cout << "Enter group number" << std::endl;
                        if (department.delete_group(
                                validate_argument(0, 10000)))
                            department_menu(position, department);
                    } else error("Group not found");
                }
                break;
            case 3:
                if (permissionFlag) {
                    std::cout << "Enter new title" << std::endl;
                    std::cin >> title;
                    if (title.empty()) error("Title cannot be empty");
                    else {
                        department.set_title(title);
                        department_menu(position, department);
                    }
                }
                break;
            case 4:
                if (permissionFlag) {
                    if (!department.get_department().empty()) {
                        std::cout << "Enter group number" << std::endl;
                        Group *g = department.find_group(validation());
                        if (g != nullptr) {
                            group_interface(*g, university);
                            department_menu(position, department);
                        }
                    } else error("Department not found");
                }
                break;
            case 5:
                if (permissionFlag) {
                    int mode;
                    std::cout << "Select search attribute(0 - Surname, 1 - Name, 2 - Patronymic, 3 - Gender)"
                              << std::endl;
                    mode = validate_argument(0, 3);
                    students_menu(university.find_student(mode));
                }
                break;
            case 6:
                if (permissionFlag) {
                    university.write(false);
                }
                break;
            case 7:
                if (permissionFlag) {
                    if (university.read(false)) {
                        department_menu(position, department);
                    }
                }
                break;
            case 8:
                if (permissionFlag) {
                    return;
                }
                break;
            case 9:
                if (permissionFlag) {
                    std::cout << "Save before exit?(1 - Yes, 2 - No)" << std::endl;
                    choice(YN);
                    if (YN == '1') {
                        university.write(false);
                    }
                    exit(0);
                }
            default:
                break;
        }
    }
}

void Interface::group_menu(int pos, Group &group){
    system("cls");
    bool flag = false;
    std::string gender;
    printf("Select option:\n");
    printf("1.Add student%s\n", pos == 1 ? " <--" : " ");
    printf("2.Remove student%s\n", pos == 2 ? " <--" : " ");
    printf("3.Edit group number%s\n", pos == 3 ? " <--" : " ");
    printf("4.Edit students%s\n", pos == 4 ? " <--" : " ");
    printf("5.Save data%s\n", pos == 5 ? " <--" : " ");
    printf("6.Load data%s\n", pos == 6 ? " <--" : " ");
    printf("7.Return to department%s\n", pos == 7 ? " <--" : " ");
    printf("8.Exit%s\n", pos == 8 ? " <--" : " ");
    std::cout << "Group number: " << group.get_number() << std::endl;
    std::cout << "Students: " << std::endl;
    for (const Student &student: group.get_group()) {
        gender = (student.get_gender() == man) ? "- man" : "- woman";
        std::cout << student.get_name() << " " << student.get_surname() << " " << student.get_patronymic() << " "
                  << gender << std::endl;
        flag = true;
    }
    if (flag)std::cout << std::endl;
}
void Interface::group_interface(Group &group, University &university){
    bool exitFlag = false, permissionFlag;
    short symbol;
    short position = 1;
    char YN;
    group_menu(position, group);
    while (!exitFlag) {
        permissionFlag = false;
        symbol = (short) getch();
        if (symbol == FIRST_BYTE_ARROW) symbol = (short) getch();
        switch (symbol) {
            case ARROW_UP:
                if (0 != position - 1)
                    position--;
                else position = MAX_ARROW_POSITION_UNI_AND_STUD;
                break;
            case ARROW_DOWN:
                if (position < MAX_ARROW_POSITION_UNI_AND_STUD) position++;
                else
                    position = MIN_ARROW_POSITION;
                break;
            case W:
                if (0 != position - 1)
                    position--;
                else position = MAX_ARROW_POSITION_UNI_AND_STUD;
                break;
            case S:
                if (position < MAX_ARROW_POSITION_UNI_AND_STUD) position++;
                else
                    position = MIN_ARROW_POSITION;
                break;
            case ESC:
                exitFlag = true;
                break;
            case ENTER:
                permissionFlag = true;
                break;
            case ONE:
                position = 1;
                break;
            case TWO:
                position = 2;
                break;
            case THREE:
                position = 3;
                break;
            case FOUR:
                position = 4;
                break;
            case FIVE:
                position = 5;
                break;
            case SIX:
                position = 6;
                break;
            case SEVEN:
                position = 7;
                break;
            case EIGHT:
                position = 8;
                break;
            default:;
        }
        group_menu(position, group);
        switch (position) {
            case 1:
                if (permissionFlag) {
                    group.add_student();
                    group_menu(position, group);
                }
                break;
            case 2:
                if (permissionFlag) {
                    if (!group.get_group().empty()) {
                        if (group.delete_student(
                                validate_string("Enter student surname", true)))
                            group_menu(position, group);
                    } else error("Group not found");
                }
                break;
            case 3:
                if (permissionFlag) {
                    std::cout << "Enter new number" << std::endl;
                    group.set_number(validate_argument(0, 10000));
                    group_menu(position, group);
                }
                break;
            case 4:
                if (permissionFlag) {
                    if (!group.get_group().empty()) {
                        Student *s = group.find_student(validate_string("Enter student surname", true));
                        if (s != nullptr) {
                            std::cout << "Select data to change(1 - Surname, 2 - Name, 3 - Patronymic, 4 - Gender)"
                                      << std::endl;
                            int choice = validate_argument(1, 4);
                            switch (choice) {
                                case 1:
                                    s->set_surname(validate_string("Enter new surname", true));
                                    break;
                                case 2:
                                    s->set_name(validate_string("Enter new name", true));
                                    break;
                                case 3:
                                    s->set_patronymic(validate_string("Enter new patronymic", true));
                                    break;
                                case 4:
                                    std::cout << "Select gender(1 - man, 2 - woman)" << std::endl;
                                    choice = validate_argument(1, 2);
                                    if (choice == 1) s->set_gender(man);
                                    else s->set_gender(woman);
                                    break;
                            }
                            group_menu(position, group);
                        }
                    } else error("Student not found");
                }
                break;
            case 5:
                if (permissionFlag) {
                    university.write(false);
                }
                break;
            case 6:
                if (permissionFlag) {
                    if (university.read(false)) {
                        group_menu(position, group);
                    }
                }
                break;
            case 7:
                if (permissionFlag) {
                    return;
                }
                break;
            case 8:
                if (permissionFlag) {
                    std::cout << "Save before exit?(1 - Yes, 2 - No)" << std::endl;
                    choice(YN);
                    if (YN == '1') {
                        university.write(false);
                    }
                    exit(0);
                }
            default:
                break;
        }
    }
}