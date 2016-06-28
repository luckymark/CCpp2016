//
//  Tools.cpp
//  Hit The Plane
//
//  Created by 陈浩贤 on 16/5/28.
//  Copyright © 2016年 陈浩贤. All rights reserved.
//

#include "Tools.hpp"
#include "ViewManagement.hpp"
#include "Game.hpp"

using namespace std;
Tool::Tool(int kind){
    if (kind==1) {
        this->type=kind;
        this->setTexture(ViewManagement::PLUSONE);
        uniform_int_distribution<unsigned>u(0,500);
        std::default_random_engine random;
        this->setPosition(u(Game::random_engine), u(Game::random_engine));
    }
}

void Tool::refresh(){
    existTime--;
}

bool Tool::needClear(){
    return this->existTime==0;
}