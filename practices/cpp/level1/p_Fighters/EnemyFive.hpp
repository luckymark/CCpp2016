//
//  EnemyFive.hpp
//  plane
//
//  Created by mac on 16/5/9.
//  Copyright © 2016年 CCPP. All rights reserved.
//

#ifndef EnemyFive_hpp
#define EnemyFive_hpp
#include "Bullet.hpp"
#include "Enemy.hpp"
#include "Texture.hpp"
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <stdio.h>
class EnemyFive : public Enemy {
  public:
    EnemyFive(int position) : Enemy(position) {
        life = 8;
        point = 10;
        setTexture(Texture::ENEMY_5);
        initialVelocity = 3;
        acceleration = 0;
        unitVector.x = -1;
        unitVector.y = 0;
    };
    void fire();
};

#endif /* EnemyFive_hpp */
