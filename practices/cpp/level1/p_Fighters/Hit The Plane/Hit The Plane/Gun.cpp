//
//  Gun.cpp
//  Hit The Plane
//
//  Created by 陈浩贤 on 16/5/19.
//  Copyright © 2016年 陈浩贤. All rights reserved.
//

#include "Gun.hpp"
#include "Bullet.hpp"
#include "Sky.hpp"
#include "Plane.hpp"
void Gun::setOwner(Plane *owner,int type){
    this->owner=owner;
    this->kind=type;
}

sf::Vector2f Gun::getPosition(){
    sf::Vector2f position;
    return position;
}

void Gun::shoot(){
    sf::Vector2f position=((this->owner)->getPosition());
    if (kind==0) {
        Bullet *bullet=new Bullet(position.x+60,position.y-20,kind);
        Sky::getInstance()->addMyBullet(bullet);
    }else if (kind==1){
        Bullet *bullet=new Bullet(position.x+25,position.y+30,kind);
        Sky::getInstance()->addEnemyBullet(bullet);
    }else if (kind==2){
        Bullet *bullet=new Bullet(position.x,position.y+30,kind);
        Sky::getInstance()->addEnemyBullet(bullet);
    }
}
