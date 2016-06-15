//
//  EnemyOne.hpp
//  plane
//
//  Created by mac on 16/5/2.
//  Copyright © 2016年 CCPP. All rights reserved.
//

#ifndef EnemyOne_hpp
#define EnemyOne_hpp
#include "Enemy.hpp"
#include "Texture.hpp"
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <stdio.h>
class EnemyOne : public Enemy {
  public:
    EnemyOne(int position) : Enemy(position) {
        initialVelocity = 3.0;
        acceleration = 0;
        unitVector.x = -1;
        unitVector.y = 0;
        point = 5;
        setTexture(Texture::ENEMY_1);
    };
    void fire();
};
#endif /* EnemyOne_hpp */
