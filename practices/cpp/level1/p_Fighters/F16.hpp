//
//  F16.hpp
//  My first app
//
//  Created by macintosh on 16/5/19.
//  Copyright © 2016年 interesting. All rights reserved.
//
#ifndef F16_hpp
#define F16_hpp
#include <stdio.h>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "ResourcePath.hpp"
#include "EnemyPlane.hpp"
#include "F35.hpp"
#include <cmath>
#include <bullet.hpp>
#include <vector>
using namespace std;
class F16:public EnemyPlane{
public:
    //飞机速度 列 行 子弹速度 射速限制
    F16(double speed2,double yy,double xx,double speed,int time):
    EnemyPlane( speed2, yy, xx, speed, time)
    {
        sprite.setTexture(F16Texture);
        ki=2.0;
    }
    void movePlane()
    {
        int i;
        posx+=planeSPeed;
        sprite.setPosition(posy,posx);
    }
    void addBullet(double my,double mx)
    {
        int p;
        double yy,xx,len;
        bulletTime=min(bulletTime+1,10000);
        if (bulletTime<bulletLimit) return;
        
        list.push_back(BulletKinds2{posy+20,posx+52});
        p=list.size();
        yy=my-posy; xx=mx-posx; if (yy==0 && xx==0) yy=1;
        len=sqrt(yy*yy+xx*xx);
        list[p-1].diry=yy/len*bulletSpeed; list[p-1].dirx=xx/len*bulletSpeed;
        list[p-1].sprite.setTexture(bulletTexture);
        list[p-1].sprite.setPosition(list[p-1].posy,list[p-1].posx);
        bulletTime=0;
    }
    void moveBullet()
    {
        int i,p;
        p=list.size();
        for (i=0;i<p;i++)
        {
            list[i].posx+=list[i].dirx;
            list[i].posy+=list[i].diry;
        }
        for (i=p-1;i>=0;i--)
        if (list[i].posy>1500 || list[i].posx>1000 || list[i].posx<0 || list[i].posy<0)
        {
            list.erase(list.begin()+i);
        }
        for (i=0;i<list.size();i++) list[i].sprite.setPosition(list[i].posy,list[i].posx);
    }
};

static bool realTouchF16(double x,double y,double px,double py)
{
    double p=52.0/20;
    if (px<x-20 || px>x+20) return false;
    if (py>y || py<y-52) return false;
    if (py>y-abs(x-px)*p) return false;
    return true;
}

static void touchF16(vector <F16> &f16,Bullet &myFire)
{
    int i,j;
    for (i=0;i<f16.size();i++)
    if (f16[i].posx>1000)
    {
        f16[i].exist=false;
        f16[i].boomtime=0;
    }
    for (i=0;i<f16.size();i++)
    if (f16[i].exist)
    {
        for (j=0;j<myFire.list.size();j++)
        if (realTouchF16(f16[i].posy+25,f16[i].posx+52,myFire.list[j].posy,myFire.list[j].posx))
        {
            myFire.point+=10;
            f16[i].exist=false;
            f16[i].boomSprite.setPosition(f16[i].posy-20, f16[i].posx);
            f16[i].boomSprite.setScale((f16[i].boomscale-f16[i].boomtime)/f16[i].boomscale/f16[i].ki, (f16[i].boomscale-f16[i].boomtime)/f16[i].boomscale/f16[i].ki);
            myFire.list.erase(myFire.list.begin()+j);
            break;
        }
    }
}
static void deleteF16(vector <F16> &f16)
{
    int i;
    for (i=f16.size()-1;i>=0;i--)
    if (!f16[i].exist)
    {
        f16[i].boomtime--;
        f16[i].boomSprite.setScale((f16[i].boomscale-f16[i].boomtime)/f16[i].boomscale/f16[i].ki, (f16[i].boomscale-f16[i].boomtime)/f16[i].boomscale/f16[i].ki);
        if (f16[i].boomtime<=0 && f16[i].list.size()==0)
        {
            f16.erase(f16.begin()+i);
        }
    }
}

static double dist(double x1,double y1,double x2,double y2)
{
    return sqrt((x1-y1)*(x1-y1)+(x2-y2)*(x2-y2));
}

static void touchBigFire(vector <F16> &f16,vector <EnemyPlane> &f22 ,vector <F35> &f35,Bullet &myFire)
{
    int i;
    double di=10000000,dx=-200,dy=250;
    for (i=0;i<f16.size();i++)
    if (f16[i].exist && dist(f16[i].posy+20,f16[i].posx,myFire.bigFirePosy+dy,myFire.bigFirePosx+dx)<=di)
    {
        myFire.point+=10;
        f16[i].exist=false;
        f16[i].boomSprite.setPosition(f16[i].posy-20, f16[i].posx);
        f16[i].boomSprite.setScale((f16[i].boomscale-f16[i].boomtime)/f16[i].boomscale/f16[i].ki, (f16[i].boomscale-f16[i].boomtime)/f16[i].boomscale/f16[i].ki);

    }
    for (i=0;i<f22.size();i++)
    if (f22[i].exist && dist(f22[i].posy+20,f22[i].posx,myFire.bigFirePosy+dy,myFire.bigFirePosx+dx)<=di)
    {
        f22[i].boomSprite.setPosition(f22[i].posy-20, f22[i].posx);
        f22[i].boomSprite.setScale((f22[i].boomscale-f22[i].boomtime)/f22[i].boomscale/f22[i].ki, (f22[i].boomscale-f22[i].boomtime)/f22[i].boomscale/f22[i].ki);
        myFire.point+=5;
        f22[i].exist=false;
    }
    for (i=0;i<f35.size();i++)
    if (f35[i].exsit && dist(f35[i].posy+20,f35[i].posx,myFire.bigFirePosy+dy,myFire.bigFirePosx+dx)<=di)
    {
        myFire.point+=20;
        f35[i].exsit=false;
        f35[i].boomSprite.setPosition(f35[i].posy-20, f35[i].posx);
        f35[i].boomSprite.setScale((f35[i].boomscale-f35[i].boomtime)/f35[i].boomscale/f35[i].ki, (f35[i].boomscale-f35[i].boomtime)/f35[i].boomscale/f35[i].ki);

    }
}
#endif /* F16_hpp */
