#include "University.h"
#include <windows.h>

class Interface{
public:

    void university_menu(int pos, University& university);
    void faculty_menu(int pos, Faculty& faculty);
    void department_menu(int pos, Department& department);
    void group_menu(int pos, Group& group);
    void students_menu(vector<string> students);

    void university_interface(University& university);
    void faculty_interface(Faculty& faculty, University& university);
    void department_interface(Department& department, University& university);
    void group_interface(Group& group, University& university);

};