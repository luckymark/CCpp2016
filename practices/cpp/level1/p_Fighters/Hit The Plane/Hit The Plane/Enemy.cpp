//
//  Enemy.cpp
//  Hit The Plane
//
//  Created by 陈浩贤 on 16/5/23.
//  Copyright © 2016年 陈浩贤. All rights reserved.
//

#include "Enemy.hpp"

#include "ViewManagement.hpp"
#include "Game.hpp"
#include <random>
#include <iostream>
#include "Sky.hpp"
using namespace std;

Enemy::Enemy(int kind){
    uniform_int_distribution<unsigned>u(0,600);
    std::default_random_engine random;
    this->setPosition(u(Game::random_engine), 20);
    
    if (kind==0) {
        this->setTexture(ViewManagement::ENEMY);
        this->gun.setOwner(this, 1);
    }else if (kind==1){
        this->setTexture(ViewManagement::BOSS01);
    }else if (kind==2){
        this->setTexture(ViewManagement::BOSS02);
    }else if (kind==3){
        this->setTexture(ViewManagement::BOSS03);
    }
    
    if (kind!=0) {
        state=7;
        speed=0.1;
        this->gun.setOwner(this,2);
    }
    
}

void Enemy::shoot(){
    fireSpacing--;
    if (fireSpacing==0) {
        this->gun.shoot();
        fireSpacing=1200;
    }
    
}
 
void Enemy::hit(){
    state--;
}

bool Enemy::needClear(){
    sf::Vector2f next;
    next.x=0;
    next.y=speed;
    return this->isOutOfWindow(next);
}

bool Enemy::isDead(){
    return state==0;
}

void Enemy::dieNow(){
    state=0;
}

void Enemy::goDown(){
    this->move(0, speed);
}

void Enemy::explode(){
    if (speed!=0) {
        speed=0;
        fireSpacing=-1;
        this->setTexture(ViewManagement::EXPLOSION);
    }
}


