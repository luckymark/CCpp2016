//
//  Hero.hpp
//  plane
//
//  Created by mac on 16/5/1.
//  Copyright © 2016年 CCPP. All rights reserved.
//

#ifndef Hero_hpp
#define Hero_hpp
#include "Bullet.hpp"
#include "Gun.hpp"
#include "Object.hpp"
#include "Score.hpp"
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <cstring>
#include <iostream>
#include <stdio.h>
#include "Timer.hpp"
#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3
class Hero : public Object {
  private:
    Hero();
    void fire();
    void move();
    bool direction[4];
    Sprite blood;
    bool blooding = 0;
    Timer clock;
    Gun gun_1;
    Gun gun_2;
    double speed;
    bool onFire;
    int life;
    int luck;
    double damage_1;
    double damage_2;
    bool magnetic;
  public:
    bool getMagnetic();
    void autoFire();
    void setMagnetic();
    double getDamage_1();
    double getDamage_2();
    void damageUp();
    bool isDead();
    void hit();
    void healthUp();
    void luckUp();
    void speedUp();
    int getLuck();
    void initial();
    static Hero *getInstance() { return getShared().get(); }
    static std::shared_ptr<Hero> getShared() {
        static std::shared_ptr<Hero> singletion;
        if (!singletion) {
            singletion.reset(new Hero);
        }
        return singletion;
    }
    void run(sf::RenderWindow &window);
    void draw(sf::RenderWindow &window);
};
#endif /* Hero_hpp */
