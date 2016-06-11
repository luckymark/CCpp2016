#ifndef SYSTEM_H
#define SYSTEM_H
#include <Sound.h>
#include <Sprite.h>
#include <Plane.h>
#include<Bullet.h>
#include<EnemyBullet.h>
#include<Plane_enemy.h>
#include<EnemyBullet.h>
#include<BoomPlane.h>

#include <iostream>
#include<sstream>
#include<string.h>

#include <numeric>
#include <algorithm>
#include <vector>
using namespace std;

class System
{
    public:
        System();
        virtual ~System();
        void showPlane();
        void showBullet();
        void showEnemy();
        void showScore();
        void showLife();
        void showBoomPlane();
        void add(Plane plane);
        void add(Bullet bullet);
        void add(Plane_enemy enemy);
        void add(EnemyBullet enemyBullet);
        void manage();
        void moveAllBullet();
        void moveALLPlane_Enemy();
        void loadBackground();
        void showBackground();
        void loadGameOver();
        void showGameOver();
        void intersects();
    protected:
    private:
        sf::RenderWindow window;
        Plane plane;
        Bullet bullet;
        Sprite backgrounds,gameovers;
        sf::Texture backgroundt,gameovert;
        vector<Bullet> bulletList;
        vector<Plane_enemy> enemyList;
        vector<EnemyBullet> enemyBulletList;
        vector<BoomPlane> boomPlaneList;
        sf::Font font;
        sf::Text textScore;
        sf::Text textLife;
        int score = 0;
        string scoreS;
        string lifeS;
        Sound sound;
};

#endif // SYSTEM_H
