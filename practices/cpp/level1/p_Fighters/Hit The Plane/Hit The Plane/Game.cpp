//
//  Game.cpp
//  Hit The Plane
//
//  Created by 陈浩贤 on 16/5/12.
//  Copyright © 2016年 陈浩贤. All rights reserved.
//

#include "Game.hpp"

Game *Game::instance=nullptr;

Game *Game::getInstance(){
    if (!instance) {
        instance=new Game;
    }
    return instance;
}