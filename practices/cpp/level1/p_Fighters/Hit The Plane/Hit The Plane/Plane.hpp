//
//  Plane.hpp
//  Hit The Plane
//
//  Created by 陈浩贤 on 16/5/12.
//  Copyright © 2016年 陈浩贤. All rights reserved.
//

#ifndef Plane_hpp
#define Plane_hpp

#include <stdio.h>
#include "Ghost.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Gun.hpp"
using std::cout;
using std::endl;

class Plane:public Ghost{
public:
    void fire();
    bool isOutOfWindow(sf::Vector2f nextStep);
    
protected:
    Gun gun;
};
#endif /* Plane_hpp */
