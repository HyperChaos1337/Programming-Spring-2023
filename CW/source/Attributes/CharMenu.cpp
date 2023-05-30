#include "CharMenu.h"

int CharMenu::mission_number(int x){
    int mission = 0;
    if(x > 0) mission = 0;
    return mission;
}

std::string CharMenu::get_text(int cur_mission){
    std::string missionText = "";
    switch (cur_mission) {
        case 0:
            missionText = "PROCEED TO ENEMY LAIR";
            break;
        default:
            break;
    }
    return missionText;
}