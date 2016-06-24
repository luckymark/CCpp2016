//
//  EnemyFour.hpp
//  plane
//
//  Created by mac on 16/5/9.
//  Copyright © 2016年 CCPP. All rights reserved.
//

#ifndef EnemyFour_hpp
#define EnemyFour_hpp
#include "Bullet.hpp"
#include "Enemy.hpp"
#include "Hero.hpp"
#include "Texture.hpp"
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <stdio.h>
class EnemyFour : public Enemy {
  public:
    EnemyFour(int position) : Enemy(position) {
        life = 4;
        point = 10;
        setTexture(Texture::ENEMY_4);
        initialVelocity = 5;
        acceleration = 1;
        unitVector.x = -1;
        unitVector.y = 0;
        target = std::weak_ptr<Object>(Hero::getShared());
    };
    void fire();
};
#endif /* EnemyFour_hpp */
