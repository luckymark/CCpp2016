//
//  ViewManagement.cpp
//  Hit The Plane
//
//  Created by 陈浩贤 on 16/5/12.
//  Copyright © 2016年 陈浩贤. All rights reserved.
//

#include "ViewManagement.hpp"
sf::Texture ViewManagement::PLAYER;
sf::Texture ViewManagement::SKY;
sf::Texture ViewManagement::BULLET;
sf::Texture ViewManagement::ENEMY;
sf::Texture ViewManagement::GAMEOVER;
sf::Texture ViewManagement::ENEMYBULLET;
sf::Texture ViewManagement::BOSS01;
sf::Texture ViewManagement::BOSS02;
sf::Texture ViewManagement::BOSS03;
sf::Texture ViewManagement::BOSSBULLET;
sf::Texture ViewManagement::SHIELD;
sf::Texture ViewManagement::SHIELDBORDER;
sf::Texture ViewManagement::SHIELDENERGY;
sf::Texture ViewManagement::THREE;
sf::Texture ViewManagement::TWO;
sf::Texture ViewManagement::ONE;
sf::Texture ViewManagement::PLUSONE;
sf::Texture ViewManagement::CHOOSER;
sf::Texture ViewManagement::EXPLOSION;

void ViewManagement::load(){
    std::string PlayerPath=resourcePath()+"player.png";
    std::string BulletPath=resourcePath()+"bullet01.png";
    std::string EnemyPath=resourcePath()+"enemy.png";
    std::string EnemyBulletPath=resourcePath()+"bullet02.png";
    std::string BossPath01=resourcePath()+"boss01.png";
    std::string BossPath02=resourcePath()+"boss02.png";
    std::string BossPath03=resourcePath()+"boss03.png";
    std::string BossBulletPath=resourcePath()+"bullet03.png";
    std::string ShieldPath=resourcePath()+"Shield.png";
    std::string ShieldBorderPath=resourcePath()+"empty.png";
    std::string ShieldEnergyPath=resourcePath()+"full.png";
    std::string ExplosionPath=resourcePath()+"explosion.png";
    
    PLAYER.loadFromFile(PlayerPath);
    BULLET.loadFromFile(BulletPath);
    ENEMY.loadFromFile(EnemyPath);
    ENEMYBULLET.loadFromFile(EnemyBulletPath);
    BOSS01.loadFromFile(BossPath01);
    BOSS02.loadFromFile(BossPath02);
    BOSS03.loadFromFile(BossPath03);
    BOSSBULLET.loadFromFile(BossBulletPath);
    SHIELD.loadFromFile(ShieldPath);
    SHIELDBORDER.loadFromFile(ShieldBorderPath);
    SHIELDENERGY.loadFromFile(ShieldEnergyPath);
    THREE.loadFromFile(resourcePath()+"three.png");
    TWO.loadFromFile(resourcePath()+"two.png");
    ONE.loadFromFile(resourcePath()+"one.png");
    PLUSONE.loadFromFile(resourcePath()+"+1.png");
    CHOOSER.loadFromFile(resourcePath()+"choose.png");
    EXPLOSION.loadFromFile(ExplosionPath);
    SKY.loadFromFile(resourcePath()+"white.png");
    GAMEOVER.loadFromFile(resourcePath()+"gameover.png");
    
}