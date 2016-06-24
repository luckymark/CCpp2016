//
//  EnemyFactory.hpp
//  plane
//
//  Created by mac on 16/5/7.
//  Copyright © 2016年 CCPP. All rights reserved.
//

#ifndef EnemyFactory_hpp
#define EnemyFactory_hpp
#include "Enemy.hpp"
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <stdio.h>
class EnemyFactory {
  public:
    static Enemy *createEnemy(int type);
};
#endif