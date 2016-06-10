//
//  Plane.cpp
//  SFML-PLANE
//
//  Created by iam24 on 16/5/8.
//  Copyright © 2016年 iam24. All rights reserved.
//

#include "Plane.hpp"
#include <cmath>
void Plane::move(double speed)
{
    sf::Vector2f movement(0.f, 0.f);
    if (left) movement.x -= speed;
    if (right) movement.x += speed;
    if (down) movement.y += speed;
    if (up) movement.y -=speed;
    double x = sprite.getPosition().x + movement.x;
    double y = sprite.getPosition().y + movement.y;
    x = fmax(x , 0);
    x = fmin(x, 750);
    y = fmax(y, 0);
    y = fmin(y, 1200);
    sprite.setPosition(x,y);
}