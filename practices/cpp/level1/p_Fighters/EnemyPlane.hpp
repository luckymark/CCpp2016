//
//  EnemyPlane.hpp
//  My first app
//
//  Created by macintosh on 16/5/7.
//  Copyright © 2016年 interesting. All rights reserved.
//

#ifndef EnemyPlane_hpp
#define EnemyPlane_hpp
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "ResourcePath.hpp"
#include <stdio.h>
#include <vector>
static sf::Texture enemyTexture;
static sf::Texture F16Texture;
static sf::Texture bulletTexture;
static sf::Texture F35Texture;
static sf::Texture F35BoomTexture;
using namespace std;
struct BulletKinds2{
    double posy,posx,dirx,diry;
    sf::Sprite sprite;
};
class EnemyPlane{
public:
    double ki,planeSPeed,posx,posy,bulletSpeed,boomscale;
    sf::Sprite boomSprite;
    int bulletTime,bulletLimit,boomtime;
    int moveTime;
    bool direction[4],exist;
    sf::Sprite sprite;
    vector <BulletKinds2> list;
    EnemyPlane(double speed2,double yy,double xx,double speed,int time)
    {
    //飞机速度 列 行 子弹速度 射速限制
        planeSPeed=speed2;
        posx=xx;
        posy=yy;
        bulletSpeed=speed;
        bulletLimit=time;
        bulletTime=0;
        moveTime=0;
        sprite.setTexture(enemyTexture);
        sprite.setPosition(yy,xx);
        exist=true;
        boomtime=10;
        boomSprite.setTexture(F35BoomTexture);
        boomscale=boomtime+10;
        ki=1.5;
    }
    
    void movePlane()
    {
        if (direction[0]) posy=max(-10.0,posy-planeSPeed);
        if (direction[1]) posy=min(1430.0,posy+planeSPeed);
        if (direction[2]) posx=max(0.0,posx-planeSPeed);
        if (direction[3]) posx=min(400.0,posx+planeSPeed);
        sprite.setPosition(posy,posx);
        
        
        
    
    }
    void getDirection()
    {
        int i;
        moveTime=min(moveTime+1,10000);
        if (moveTime<100) return;
        for (i=0;i<4;i++) direction[i]=rand()%2;
        moveTime=0;
    }
    void addBullet()
    {
        int p;
        bulletTime=min(bulletTime+1,10000);
        if (bulletTime<bulletLimit) return;
        list.push_back(BulletKinds2{posy+62,posx+70});
        p=list.size();
        list[p-1].sprite.setTexture(bulletTexture);
        list[p-1].sprite.setPosition(posy+62,posx+70);
        bulletTime=0;
    }
    void moveBullet()
    {
        int i,p;
        p=list.size();
        for (i=0;i<p;i++) list[i].posx+=bulletSpeed;
        while (p!=0 && list[0].posx>1000)
        {
            for (i=0;i<p-1;i++) swap(list[i],list[i+1]);
            list.pop_back();
            p--;
        }
        for (i=0;i<p;i++) list[i].sprite.setPosition(list[i].posy,list[i].posx);
    }
};
#endif /* EnemyPlane_hpp */
