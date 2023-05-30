#ifndef TESTCW_CHARMENU_H
#define TESTCW_CHARMENU_H

#include <string>

class CharMenu{
public:
    int mission_number(int x);
    std::string get_text(int cur_mission);
};

#endif