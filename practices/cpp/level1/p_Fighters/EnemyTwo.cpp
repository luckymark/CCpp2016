//
//  EnemyTwo.cpp
//  plane
//
//  Created by mac on 16/5/4.
//  Copyright © 2016年 CCPP. All rights reserved.
//

#include "BulletOne.hpp"
#include "EnemyTwo.hpp"
#include "Stage.hpp"
void EnemyTwo::fire() {
    sf::Time elapsed = clock.getElapsedTime();
    if (elapsed.asSeconds() <= 2) {
        return;
    }
    clock.restart();
    Stage::getInstance()->creatBullet(
        new BulletOne(getPosition().x - 90, getPosition().y));
}