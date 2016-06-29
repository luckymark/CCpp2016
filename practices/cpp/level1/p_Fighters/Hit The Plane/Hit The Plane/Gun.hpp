//
//  Gun.hpp
//  Hit The Plane
//
//  Created by 陈浩贤 on 16/5/19.
//  Copyright © 2016年 陈浩贤. All rights reserved.
//

#ifndef Gun_hpp
#define Gun_hpp

#include <stdio.h>
#include <SFML/Graphics.hpp>

class Plane;

class Gun{
public:
    
    void setOwner(Plane *owner,int type);
    void shoot();
private:
    sf::Vector2f getPosition();
    Plane *owner;
    int kind;
    int count=0;
}; 
#endif /* Gun_hpp */
