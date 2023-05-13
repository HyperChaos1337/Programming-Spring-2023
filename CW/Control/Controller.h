#ifndef COURSE_WORK_2_CONTROLLER_H
#define COURSE_WORK_2_CONTROLLER_H

#include "../Entities/Player.h"

class Controller{
private:
    Player* player;
public:
    Controller(Player* player);
    void control();
};

#endif