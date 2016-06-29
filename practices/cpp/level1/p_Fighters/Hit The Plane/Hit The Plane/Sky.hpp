//
//  Sky.hpp
//  Hit The Plane
//
//  Created by 陈浩贤 on 16/5/12.
//  Copyright © 2016年 陈浩贤. All rights reserved.
//

#ifndef Sky_hpp
#define Sky_hpp

#include <stdio.h>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <unordered_set>

#include "Ghost.hpp"
#include "Bullet.hpp"
#include "Enemy.hpp"
#include "Player.hpp"
#include "Tools.hpp"
using namespace std;

class Sky{
public:
    static Sky *getInstance();
    sf::RenderWindow *getWindow(){
        return this->window;
    }
    void add(Ghost *);
    void addMyBullet(Bullet *);
    void addPlayer(Player *);
    void addEnemyBullet(Bullet *);
    void addBars(Ghost *bar);
    void refresh();
    void drawStatic();
    void moveChosser(int position);
    void clearAll();
    void restartGame();
private:
    Sky();
    
    sf::RenderWindow *window;
    
    sf::Sprite *backgroud=nullptr;
    unordered_set<Bullet*>myBullets;
    unordered_set<Enemy *>enemies;
    unordered_set<Bullet*>enemyBullets;
    unordered_set<Enemy *>bosses;
    unordered_set<Ghost *>bars;
    unordered_set<Tool *>tools;
    unordered_set<Enemy *>deadEnemies;
    
    Player *player;
    
    static Sky *instance;
    
    void clear();
    void collision();
    void creatEnemies();
    void playerIsDead();
    void loopTheEnemyBullet();
    void loopTheTools();
    int count=0;
    int spacing=500;
    int enemyCount=1;
    
};

#endif /* Sky_hpp */
