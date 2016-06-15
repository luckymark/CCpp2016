//
//  EnemyThree.cpp
//  plane
//
//  Created by mac on 16/5/7.
//  Copyright © 2016年 CCPP. All rights reserved.
//

#include "BulletOne.hpp"
#include "BulletTwo.hpp"
#include "EnemyThree.hpp"
#include "Hero.hpp"
#include "Stage.hpp"
#include <cmath>
void EnemyThree::fire() {
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