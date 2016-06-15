//
//  bullet.hpp
//  My first app
//
//  Created by macintosh on 16/5/6.
//  Copyright © 2016年 interesting. All rights reserved.
//
#ifndef bullet_hpp
#define bullet_hpp
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "ResourcePath.hpp"
#include "MovePlane.hpp"
#include <stdio.h>
#include "EnemyPlane.hpp"
#include <cstring>
#include <vector>
using namespace std;
struct BulletKinds{
    double posy,posx;
    sf::Sprite sprite;
};
class Bullet{
public:
    double bigFireBoomscale,bigFireSpeed,bulletSpeed,bigFirePosy,bigFirePosx;
    double bigFireBoomKi,bigFireMove;
    int boomTime,bigFireBoomTime,point,bulletTime,bulletLimit,bigFireNum,bigFireTime;
    bool fire,bigFireP;
    string str;
    string bigFireString;
    sf::Texture texture;
    sf::Text grade;
    sf::Text bigFireText;
    sf::Texture bigFireTexture;
    sf::Sprite bigFireSprite;
    sf::Texture bigFireBoomTexture;
    sf::Sprite bigFireBoomSprite;
    vector <BulletKinds> list;
    Bullet(double Speed,int Time,sf::Font &font)
    {
        point=0;
        fire=false;
        bulletLimit=Time;
        bulletSpeed=Speed;
        bulletTime=0;
        texture.loadFromFile(resourcePath()+"我方子弹.png");
        bigFireBoomTexture.loadFromFile(resourcePath()+"大招爆炸效果.png");
        bigFireBoomSprite.setTexture(bigFireBoomTexture);
        
        bigFireTexture.loadFromFile(resourcePath()+"大招.png");
        bigFireSprite.setScale(1.2,1.2);
        bigFireSprite.setTexture(bigFireTexture);
        bigFireNum=5; bigFireTime=10000; bigFireP=false;
        bigFireBoomKi=0.02; boomTime=1;
        bigFireBoomTime=0;
        
        bigFireSpeed=8;
        bigFireText.setFont(font);
        bigFireText.setCharacterSize(20);
        bigFireText.setPosition(50,77);
        
        str=to_string(point);
        grade.setFont(font);
        grade.setCharacterSize(30);
        grade.setString(str);
        grade.setPosition(75,960);
    }
    void clear()
    {
        point=0;
        fire=false;
        bulletTime=0;
        list.clear();
        str=to_string(point);
        grade.setCharacterSize(30);
        grade.setString(str);
        grade.setPosition(75,960);
    }
    void addBullet(double y,double x)
    {
        int p;
        if (bulletTime<bulletLimit) return;
        list.push_back(BulletKinds{y+42,x});
        p=list.size();
        list[p-1].sprite.setTexture(texture);
        list[p-1].sprite.setPosition(y,x);
        bulletTime=0;
    }
    
    void moveBullet()
    {
        int i,p;
        bulletTime=min(bulletTime+1,10000);
        p=list.size();
        for (i=0;i<p;i++) list[i].posx+=-bulletSpeed;
        while (p!=0 && list[0].posx<0)
        {
            list.erase(list.begin());
            p--;
        }
        for (i=0;i<p;i++) list[i].sprite.setPosition(list[i].posy,list[i].posx);
    }
    
    void deleteBigFire()
    {
        bigFireP=false;
        bigFireBoomSprite.setPosition(bigFirePosy-3400,bigFirePosx-3000);
        bigFireBoomTime=20; bigFireBoomscale=bigFireBoomTime+20;
        bigFireBoomSprite.setScale((bigFireBoomscale-bigFireBoomTime)/bigFireBoomscale/bigFireBoomKi,(bigFireBoomscale-bigFireBoomTime)/bigFireBoomscale/bigFireBoomKi);
    }
    
    void updatePoint()
    {
        str=to_string(point);
        grade.setString(str);
        bigFireString=to_string(bigFireNum);
        bigFireText.setString(bigFireString);
        bigFireTime=min(bigFireTime+1,10000);
        if (bigFireP)
        {
            bigFireMove+=bigFireSpeed;
            bigFirePosx=max(bigFirePosx-bigFireSpeed,0.0);
            if (bigFirePosx==0.0) bigFireMove=10000;
            bigFireSprite.setPosition(bigFirePosy,bigFirePosx);
            if (bigFireMove>=700)
            {
                deleteBigFire();
            }
        }
        bigFireBoomTime=max(0,bigFireBoomTime-boomTime);
        if (bigFireBoomTime!=0)
            bigFireBoomSprite.setScale((bigFireBoomscale-bigFireBoomTime)/bigFireBoomscale/bigFireBoomKi,(bigFireBoomscale-bigFireBoomTime)/bigFireBoomscale/bigFireBoomKi);
    }
    void addBigFire(double &posy,double &posx)
    {
        bigFireP=true;   bigFireMove=0; bigFireTime=0; bigFireNum--;
        bigFirePosx=posx+bigFireSpeed;  bigFirePosy=posy+9;
    }
};
#endif /* bullet_hpp */
