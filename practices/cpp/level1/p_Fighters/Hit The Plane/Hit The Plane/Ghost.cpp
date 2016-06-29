//
//  Ghost.cpp
//  Hit The Plane
//
//  Created by 陈浩贤 on 16/5/12.
//  Copyright © 2016年 陈浩贤. All rights reserved.
//

#include "Ghost.hpp"
#include "Sky.hpp"
void Ghost::draw(){
    Sky::getInstance()->getWindow()->draw(*this);
}

bool Ghost::intersects(Ghost *other){
    bool t=this->getGlobalBounds().intersects(other->getGlobalBounds());
    return t;
}