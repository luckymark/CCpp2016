//
//  Plane.hpp
//  SFML-PLANE
//
//  Created by iam24 on 16/5/8.
//  Copyright © 2016年 iam24. All rights reserved.
//

#ifndef Plane_hpp
#define Plane_hpp
#include <SFML/Graphics.hpp>
#include <stdio.h>
class Plane
{
public:
    bool right =false,left = false,up = false,down = false ;
    virtual void move(double speed);
    //sf:: Texture texture;
    sf:: Sprite sprite;
    double speed;
    int health;
};
#endif /* Plane_hpp */
