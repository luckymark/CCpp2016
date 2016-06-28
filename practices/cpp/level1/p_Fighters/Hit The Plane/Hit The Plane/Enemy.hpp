//
//  Enemy.hpp
//  Hit The Plane
//
//  Created by 陈浩贤 on 16/5/23.
//  Copyright © 2016年 陈浩贤. All rights reserved.
//

#ifndef Enemy_hpp
#define Enemy_hpp

#include <stdio.h>
#include "Plane.hpp"
using namespace std;
class Enemy:public Plane{
public:
    Enemy(int kind);
    
    void shoot();
    void hit();
    bool needClear();
    void dieNow();
    void goDown();
    void explode();
    bool isDead();
    int deadTime=0;
private:
    int state=2;
    int fireSpacing=200;
    int type;
    float speed=0.5;
    
protected:
    Gun gun;
};
#endif /* Enemy_hpp */
