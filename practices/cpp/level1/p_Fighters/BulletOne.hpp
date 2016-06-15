//
//  BulletOne.hpp
//  plane
//
//  Created by mac on 16/5/8.
//  Copyright © 2016年 CCPP. All rights reserved.
//

#ifndef BulletOne_hpp
#define BulletOne_hpp
#include "SecondaryObject.hpp"
#include "Texture.hpp"
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <stdio.h>
class BulletOne : public SecondaryObject {
  public:
    BulletOne(double positionX, double positionY, double unitVectorX = -1,
              double unitVectorY = 0) {
        initialVelocity = 10.0;
        acceleration = 0;
        unitVector.x = unitVectorX;
        unitVector.y = unitVectorY;
        setPosition(positionX, positionY);
        deviation.x = 50;
        deviation.y = 50;
        radius = 25;
        setTexture(Texture::ENEMY_BULLET);
    };
};
#endif /* BulletOne_hpp */
