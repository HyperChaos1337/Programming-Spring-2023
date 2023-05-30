#include "Enemy.h"

Enemy::Enemy(AnimationManager &a, Level &lev, int x, int y):Entity(a,x,y){
    option("Enemy", 0.01, 15, "move");
    obj = lev.GetAllObjects();
}

void Enemy::update(float time){
    x+=dx*time;
    timer+=time;
    if (timer>12800) {dx*=-1;timer=0;}
    collision();
    if (Health<=0) {anim.set("dead"); dx=0;
        timer_end+=time;
        if (timer_end>4000) life=false;
    }

    anim.tick(time);
}

void Enemy::collision(){
    for(int i = 0; i < obj.size(); i++){
        if(getRect().intersects(obj[i].rect)){
            if(obj[i].name == "solid" || obj[i].name == "border"){
                if (dx>0){
                    x =  obj[i].rect.left -  w;
                }
                if (dx<0){
                    x =  obj[i].rect.left + obj[i].rect.width ;
                }
                dx *= -1;
            }
        }
    }
}