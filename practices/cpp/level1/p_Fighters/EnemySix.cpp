//
//  EnemySix.cpp
//  plane
//
//  Created by mac on 16/5/12.
//  Copyright © 2016年 CCPP. All rights reserved.
//

#include "BulletOne.hpp"
#include "BulletTwo.hpp"
#include "EnemySix.hpp"
#include "Stage.hpp"
void EnemySix::fire() {
    sf::Time elapsed = clock.getElapsedTime();
    if (elapsed.asSeconds() <= 2) {
        return;
    }
    clock.restart();
    sf::Vector2f step = getUnitVector(this, Hero::getInstance());
    SecondaryObject *bullet = NULL;
    if (step.x > 0) {
        bullet = new BulletOne(getPosition().x - 90, getPosition().y);
    } else {
        bullet = new BulletTwo(getPosition().x - 90, getPosition().y);
    }
    Stage::getInstance()->creatBullet(bullet);
}
bool EnemySix::isDead() {
    if (life <= 1e-6) {
        Stage::getInstance()->creatBullet(
            new BulletOne(getPosition().x + 25, getPosition().y + 25));
        Stage::getInstance()->creatBullet(
            new BulletOne(getPosition().x + 25, getPosition().y + 25, 1, 0));
        Stage::getInstance()->creatBullet(
            new BulletOne(getPosition().x + 25, getPosition().y + 25, 0, 1));
        Stage::getInstance()->creatBullet(
            new BulletOne(getPosition().x + 25, getPosition().y + 25, 0, -1));
    }
    return (life <= 1e-6);
}
