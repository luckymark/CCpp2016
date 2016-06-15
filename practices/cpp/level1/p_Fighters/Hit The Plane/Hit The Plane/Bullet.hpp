//
//  Bullet.hpp
//  Hit The Plane
//
//  Created by 陈浩贤 on 16/5/19.
//  Copyright © 2016年 陈浩贤. All rights reserved.
//

#ifndef Bullet_hpp
#define Bullet_hpp

#include <stdio.h>
#include "Ghost.hpp"
using namespace std;
class Bullet:public Ghost{
public:
    Bullet(float x,float y,int owner);
    
    void goDown();
    void goUp();
    bool isOutOfWindow();
    
};
#endif /* Bullet_hpp */
