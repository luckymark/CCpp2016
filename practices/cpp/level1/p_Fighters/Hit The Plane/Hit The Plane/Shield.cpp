//
//  Shield.cpp
//  Hit The Plane
//
//  Created by 陈浩贤 on 16/5/27.
//  Copyright © 2016年 陈浩贤. All rights reserved.
//

#include "Shield.hpp"
#include "ViewManagement.hpp"
#include "Sky.hpp"
void Shield::setOwner(Ghost *owner){
    this->shieldOwner=owner;
    this->setPosition(20, 700);
    this->setTexture(ViewManagement::SHIELDENERGY);
    Sky::getInstance()->addBars(this);
}

void Shield::open(){
    if (energy>=0) {
        energy--;
        this->shieldOwner->setTexture(ViewManagement::SHIELD);
        this->isOpened=true;
    }else{
        this->shieldOwner->setTexture(ViewManagement::PLAYER);
        this->isOpened=false;
    }
}

void Shield::charge(){
    if (energy<=300) {
        energy++;
    }
    this->isOpened=false;
    this->shieldOwner->setTexture(ViewManagement::PLAYER);
}

void Shield::refresh(){
    this->setTextureRect(sf::IntRect(0,0,energy,90));
}

bool Shield::isOpen(){
    return this->isOpened;
}