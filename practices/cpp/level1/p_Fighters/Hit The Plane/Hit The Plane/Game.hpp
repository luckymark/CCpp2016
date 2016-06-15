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
#include "Player.hpp"
class Game{
public:
    static Game *getInstance();
    static std::default_random_engine random_engine;
    
    void scored();
    int getScore();
    int getBestScore();
    void isGameOver();
    void setPlayer(Player *thePlayer);
    void restartGame();
private:
    static Game *instance;
    int score=0;
    Player *player;
    void resetScore();
    
};
#endif /* Game_hpp */
