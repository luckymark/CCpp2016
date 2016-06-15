//
//  EnemyTwo.hpp
//  plane
//
//  Created by mac on 16/5/4.
//  Copyright © 2016年 CCPP. All rights reserved.
//

#ifndef EnemyTwo_hpp
#define EnemyTwo_hpp
#include "Bullet.hpp"
#include "Enemy.hpp"
#include "Texture.hpp"
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <stdio.h>
class EnemyTwo : public Enemy {
  public:
    EnemyTwo(int position) :Enemy(position){
        point = 10;
        setTexture(Texture::ENEMY_2);
        initialVelocity = 3.0;
        acceleration = 0;
        unitVector.x = -1;
        unitVector.y = 0;
    };
    void fire();
};

#endif /* EnemyTwo_hpp */
