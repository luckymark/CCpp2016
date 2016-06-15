//
//  Bullet.hpp
//  plane
//
//  Created by mac on 16/5/1.
//  Copyright © 2016年 CCPP. All rights reserved.
//

#ifndef Bullet_hpp
#define Bullet_hpp
#include "SecondaryObject.hpp"
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <stdio.h>
#include <vector>
class Bullet : public SecondaryObject {
  public:
    double damage;
};

#endif /* Bullet_hpp */
