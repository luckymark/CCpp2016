//
//  Player.hpp
//  Hit The Plane
//
//  Created by 陈浩贤 on 16/5/12.
//  Copyright © 2016年 陈浩贤. All rights reserved.
//

#ifndef Player_hpp
#define Player_hpp

#include <stdio.h>
#include "Plane.hpp"
#include "Shield.hpp"
class Player:public Plane{
public:
    Player();
    
    void moveToLeft();
    void moveToRight();
    void moveToUp();
    void moveToDown();
    void isHit();
    void openShield();
    void closeShield();
    bool isDead();
    bool ifShieldOpened();
    int getState();
    void plusone();
    void reborn();
private:
    sf::Vector2f next;
    sf::Vector2f position;
    int state=3;
    Shield shield;
};
#endif /* Player_hpp */
