//
//  HeroBullet.hpp
//  plane
//
//  Created by mac on 16/5/8.
//  Copyright © 2016年 CCPP. All rights reserved.
//

#ifndef HeroBullet_hpp
#define HeroBullet_hpp
#include "Bullet.hpp"
#include "Texture.hpp"
#include <Hero.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <stdio.h>
class HeroBullet : public Bullet {
  public:
    HeroBullet(double positionX, double positionY) {
        initialVelocity = 20.0;
        acceleration = 0;
        unitVector.x = 1;
        unitVector.y = 0;
        this->damage = Hero::getInstance()->getDamage_1();
        setTexture(Texture::BULLET);
        setPosition(positionX, positionY);
        deviation.x = 55;
        deviation.y = 50;
        radius = 25;
    };
};
#endif /* HeroBullet_hpp */
