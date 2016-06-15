//
//  EnemySix.hpp
//  plane
//
//  Created by mac on 16/5/12.
//  Copyright © 2016年 CCPP. All rights reserved.
//

#ifndef EnemySix_hpp
#define EnemySix_hpp
#include "Enemy.hpp"
#include "Texture.hpp"
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <stdio.h>
class EnemySix : public Enemy {
  public:
    EnemySix(int position) : Enemy(position) {
        point = 15;
        life = 8;
        setTexture(Texture::ENEMY_3);
        initialVelocity = 3.0;
        acceleration = 0;
        unitVector.x = -1;
        unitVector.y = 0;
    };
    bool isDead();
    void fire();
};
#endif /* EnemySix_hpp */
