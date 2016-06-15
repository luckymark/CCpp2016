//
//  F35.hpp
//  My first app
//
//  Created by macintosh on 16/5/23.
//  Copyright © 2016年 interesting. All rights reserved.
//

#ifndef F35_hpp
#define F35_hpp
#include <stdio.h>
#include <cmath>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "ResourcePath.hpp"
#include "EnemyPlane.hpp"
#include "bullet.hpp"
#include <vector>
class F35{
public:
    double ki,boomscale,posy,posx,speed;
    sf::Sprite sprite;
    sf::Sprite boomSprite;
    bool exsit;
    int boomtime;
    F35(double y,double x,double speedPlane)
    {
        posy=y; posx=x; speed=speedPlane;
        sprite.setTexture(F35Texture);
        sprite.setScale(2,2);
        sprite.setPosition(posy,posx);
        boomSprite.setTexture(F35BoomTexture);
        boomSprite.setColor(sf::Color(255,255,255,255));
        exsit=true;
        boomtime=10;
        boomscale=boomtime+10;
        ki=0.7;
       // boomMusic.(resourcePath()+"F35爆炸.wav");
    }
    void movePlane(double y,double x)
    {
        double len;
        y=y-posy; x=x-posx;
        if (y==0 && x==0) x=1;
        len=sqrt(x*x+y*y);
        posx+=x/len*speed;
        posy+=y/len*speed;
        sprite.setPosition(posy,posx);
    }
};
static void deleteF35(vector <F35> &f35)
{
    int i;
    for (i=f35.size()-1;i>=0;i--)
    {
     if (f35[i].exsit==false)
     {
         f35[i].boomtime--;
         if (f35[i].boomtime>0)
         {
             f35[i].boomSprite.setScale((f35[i].boomscale-f35[i].boomtime)/f35[i].boomscale/f35[i].ki, (f35[i].boomscale-f35[i].boomtime)/f35[i].boomscale/f35[i].ki);
         }
     }
     if (f35[i].exsit==false && f35[i].boomtime<=0)  f35.erase(f35.begin()+i);
    }
}

static bool realTouchF35(double mx,double my,double x,double y)
{
    double bx=38,by=50;
    double p=by/bx,now;
    if (x<mx-bx+14 || x>mx+bx) return false;
    if (y<my-by || y>my) return false;
    now=my-abs(x-mx)*p;
    if (x<mx) now-=24;
    if (now<y) return false;
    return true;
}

static void touchF35(vector <F35> &f35,Bullet &myFire)
{
    int i,j;
    for (i=f35.size()-1;i>=0;i--)
    if (f35[i].exsit)
    {
        for (j=myFire.list.size()-1;j>=0;j--)
    if (realTouchF35(f35[i].posy+38,f35[i].posx+100,myFire.list[j].posy,myFire.list[j].posx))
        {
            myFire.point+=20;
            f35[i].exsit=false;
            f35[i].boomSprite.setPosition(f35[i].posy-20, f35[i].posx);
             f35[i].boomSprite.setScale((f35[i].boomscale-f35[i].boomtime)/f35[i].boomscale/f35[i].ki, (f35[i].boomscale-f35[i].boomtime)/f35[i].boomscale/f35[i].ki);
            myFire.list.erase(myFire.list.begin()+j);
            break;
        }
    }
}
#endif /* F35_hpp */
