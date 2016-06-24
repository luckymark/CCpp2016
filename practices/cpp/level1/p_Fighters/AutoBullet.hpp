//
//  AutoBullet.hpp
//  plane
//
//  Created by mac on 16/5/19.
//  Copyright © 2016年 CCPP. All rights reserved.
//

#ifndef AutoBullet_hpp
#define AutoBullet_hpp

#include "Bullet.hpp"
#include "Texture.hpp"
#include <Hero.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <stdio.h>
#include <stdio.h>
class AutoBullet : public Bullet {
  public:
    AutoBullet(double positionX, double positionY,
               std::weak_ptr<Object> target) {
        initialVelocity = 5.0;
        acceleration = 2;
        setPosition(positionX, positionY);
        deviation.x = 50;
        deviation.y = 50;
        radius = 25;
        this->target = target;
        getUnitVector(this, target.lock().get());
        setTexture(Texture::ENEMY_BULLET_2);
        this->damage = Hero::getInstance()->getDamage_2();
    };
};
#endif /* AutoBullet_hpp */
