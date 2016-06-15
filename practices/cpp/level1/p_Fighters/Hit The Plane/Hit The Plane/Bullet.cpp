//
//  Bullet.cpp
//  Hit The Plane
//
//  Created by 陈浩贤 on 16/5/19.
//  Copyright © 2016年 陈浩贤. All rights reserved.
//

#include "Bullet.hpp"
#include "ViewManagement.hpp"
Bullet::Bullet(float x,float y,int owner){
    if (owner==0) {
        this->setTexture(ViewManagement::BULLET);
    }else if (owner==1){
        this->setTexture(ViewManagement::ENEMYBULLET);
    }else if (owner==2){
        this->setTexture(ViewManagement::BOSSBULLET);
    }
    
    this->setPosition(x, y);
}

void Bullet::goUp(){
    this->move(0, -2);
}

void Bullet::goDown(){
    this->move(0, 1);
}

bool Bullet::isOutOfWindow(){
    sf::Vector2f position=this->getPosition();
    return position.x>800||position.x<-30||position.y>1200||position.y<-20;
}