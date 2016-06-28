//
//  Player.cpp
//  Hit The Plane
//
//  Created by 陈浩贤 on 16/5/12.
//  Copyright © 2016年 陈浩贤. All rights reserved.
//

#include "Player.hpp"
#include "ViewManagement.hpp"
#define STEP 2;
Player::Player(){
    this->setTexture(ViewManagement::PLAYER);
    this->setPosition(250, 600);
    this->gun.setOwner(this, 0);
    this->shield.setOwner(this);
}

void Player::moveToLeft(){
    next.x=-STEP;
    next.y=0;
    position=this->getPosition();
    if (!this->isOutOfWindow(next)) {
        this->move(next);
    }
}

void Player::moveToRight(){
    next.x=STEP;
    next.y=0;
    position=this->getPosition();
    if (!this->isOutOfWindow(next)) {
        this->move(next);
    }
}

void Player::moveToUp(){
    next.x=0;
    next.y=-STEP;
    position=this->getPosition();
    if (!this->isOutOfWindow(next)) {
        this->move(next);
    }
}

void Player::moveToDown(){
    next.x=0;
    next.y=STEP;
    position=this->getPosition();
    if (!this->isOutOfWindow(next)) {
        this->move(next);
    }
}

void Player::isHit(){
    if (state>0) {
        state--;
    }
}

bool Player::isDead(){
    return state==0;
}

void Player::openShield(){
    this->shield.open();
}

void Player::closeShield(){
    this->shield.charge();
}

bool Player::ifShieldOpened(){
    return this->shield.isOpen();
}

int Player::getState(){
    return this->state;
}

void Player::plusone(){
    if (state<3) {
        state++;
    }
}

void Player::reborn(){
    state=3;
}