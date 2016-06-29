//
//  Plane.cpp
//  Hit The Plane
//
//  Created by 陈浩贤 on 16/5/12.
//  Copyright © 2016年 陈浩贤. All rights reserved.
//

#include "Plane.hpp"

void Plane::fire(){
    this->gun.shoot();
}

bool Plane::isOutOfWindow(sf::Vector2f nextStep){
    sf::Vector2f position=this->getPosition();
    position=position+nextStep;
    return position.x>450||position.x<-30||position.y>700||position.y<-20;
}