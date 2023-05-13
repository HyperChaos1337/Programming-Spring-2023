#include "Controller.h"

Controller::Controller(Player *player){
    this->player = player;
}

void Controller::control(){
    if (Keyboard::isKeyPressed(Keyboard::A)) {
        player->dx = -0.1;
    }

    if (Keyboard::isKeyPressed(Keyboard::D)) {
        player->dx = 0.1;
    }

    if(Keyboard::isKeyPressed(Keyboard::W)){
        player->dy = -0.1;
    }

    if(Keyboard::isKeyPressed(Keyboard::S)){
        player->dy = 0.1;
    }
}