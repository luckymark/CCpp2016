//
//  Stage.hpp
//  plane
//
//  Created by mac on 16/5/1.
//  Copyright © 2016年 CCPP. All rights reserved.
//

#ifndef Stage_hpp
#define Stage_hpp
#include "Bullet.hpp"
#include "Cloud.hpp"
#include "Enemy.hpp"
#include "EnemyOne.hpp"
#include "Particle.hpp"
#include "Pickup.hpp"
#include "Texture.hpp"
#include "iostream"
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <Timer.hpp>
#include <list>
#include "Effect.hpp"
#include <stdio.h>
class Stage : public sf::Sprite {
  private:
    Stage();
    std::list<std::shared_ptr<Bullet>> myBullet;
    std::list<std::shared_ptr<SecondaryObject>> enemyBullet;
    std::list<std::shared_ptr<Enemy>> allEnemy;
    std::list<std::shared_ptr<Pickup>> allPickup;
    std::list<Effect *> allEffect;
    Timer clock;
    Timer coolDown;

  public:
    static Stage *getInstance() {
        static Stage *singleton;
        if (singleton == NULL) {
            singleton = new Stage();
        }
        return singleton;
    }
    int difficulty = 3;
    int stage = 0;
    void initial();
    int run();
    int collision();
    std::weak_ptr<Object> getEnemy();
    void draw(sf::RenderWindow &window);
    void creatBullet(Bullet *bullet);
    void creatCloud(Cloud *cloud);
    void creatParticle(Particle *particle);
    void creatBullet(SecondaryObject *bullet);
    void creatEnemy(Enemy *enemy);
    void creatPickup(Pickup *pickup);
};
#endif /* Stage_hpp */
