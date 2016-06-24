//
//  EnemyFive.cpp
//  plane
//
//  Created by mac on 16/5/9.
//  Copyright © 2016年 CCPP. All rights reserved.
//

#include "BulletOne.hpp"
#include "EnemyFive.hpp"
#include "Stage.hpp"
#include <cmath>
void EnemyFive::fire() {
    sf::Time elapsed = clock.getElapsedTime();
    if (elapsed.asSeconds() <= 2) {
        return;
    }
    clock.restart();
    Stage::getInstance()->creatBullet(new BulletOne(
        getPosition().x - 90, getPosition().y, -cos(0.1), sin(0.1)));
    Stage::getInstance()->creatBullet(new BulletOne(
        getPosition().x - 90, getPosition().y, -cos(0.1), -sin(0.1)));
}