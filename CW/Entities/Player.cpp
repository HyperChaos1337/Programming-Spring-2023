#include "Player.h"

Player::Player(sf::Texture &image){
    sprite.setTexture(image);
    rect = FloatRect (100, 100, 50, 60);
    dx = dy = 0;
    frame = 0;
}

void Player::update(float time){

    rect.left += dx*time;
    rect.top += dy*time;
    frame += 0.005;
    if (frame > 3) frame -= 3;

    //Horizontal movement
    if(dx > 0 && dy == 0) sprite.setTextureRect(IntRect(70 * int(frame)+50, 178, -50, 70));
    if(dx < 0 && dy == 0) sprite.setTextureRect(IntRect(70 * int(frame), 178, 50, 70));
    //Vertical movement

    if(dx == 0 && dy > 0) sprite.setTextureRect(IntRect(70 * int(frame), 178, 50, 60));
    if(dx == 0 && dy < 0) sprite.setTextureRect(IntRect(70 * int(frame), 178, 50, 60));
    //Diagonal movement

    if(dx > 0 && dy > 0 || dx > 0 && dy < 0) sprite.setTextureRect(IntRect(70 * int(frame)+50, 178, -50, 70));
    if(dx < 0 && dy > 0 || dx < 0 && dy < 0) sprite.setTextureRect(IntRect(70 * int(frame), 178, 50, 70));



    sprite.setPosition(rect.left, rect.top);
    dx = 0;
    dy = 0;

}