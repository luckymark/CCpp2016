//
//  Enemy.hpp
//  SFML-PLANE
//
//  Created by iam24 on 16/5/10.
//  Copyright © 2016年 iam24. All rights reserved.
//

#ifndef Enemy_hpp
#define Enemy_hpp

#include "bullet.hpp"
#include "ResourcePath.hpp"
#include <SFML/Graphics.hpp>
#include <cmath>
#include "Plane.hpp"
class Enemy : public Plane
{ 
public:
    Enemy(){}
    Enemy(double speed, sf::Vector2f pos, int hp, int score);
    std::vector <Enemy> all_enemy;
    void add_enemy();
    void move();
    friend class Game;
private:
    sf::Vector2f pos;
    int enemy_limit = 20;
    int enemy_time = 0;
    static int tot_enemy;
    int enemy_boss_health = 10;
    int enemy_score = 5;
    int enemy_boss_score = 50;
    static int escape_enemy;
    int score;
};
#endif /* Enemy_hpp */
