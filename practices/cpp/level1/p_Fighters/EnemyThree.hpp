//
//  EnemyThree.hpp
//  plane
//
//  Created by mac on 16/5/7.
//  Copyright © 2016年 CCPP. All rights reserved.
//

#ifndef EnemyThree_hpp
#define EnemyThree_hpp
#include "Bullet.hpp"
#include "Enemy.hpp"
#include "Texture.hpp"
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <stdio.h>
class EnemyThree : public Enemy {
  public:
    EnemyThree(int position) : Enemy(position) {
        life = 5.0;
        point = 10;
        setTexture(Texture::ENEMY_3);
        initialVelocity = 2.5;
        acceleration = 0;
        unitVector.x = -1;
        unitVector.y = 0;
    };
    void fire();
};
#endif /* EnemyThree_hpp */
