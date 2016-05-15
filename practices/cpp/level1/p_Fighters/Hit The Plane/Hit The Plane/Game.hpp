//
//  Game.hpp
//  Hit The Plane
//
//  Created by 陈浩贤 on 16/5/12.
//  Copyright © 2016年 陈浩贤. All rights reserved.
//

#ifndef Game_hpp
#define Game_hpp

#include <stdio.h>
#include <random>
#include <ctime>

class Game{
public:
    static Game *getInstance();
    static std::default_random_engine randon_engine;
    
private:
    static Game *instance;
    
};
#endif /* Game_hpp */
