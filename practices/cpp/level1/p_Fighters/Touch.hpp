//
//  Touch.hpp
//  My first app
//
//  Created by macintosh on 16/5/9.
//  Copyright © 2016年 interesting. All rights reserved.
//

#ifndef Touch_hpp
#define Touch_hpp
#include <vector>
#include <stdio.h>
#include <EnemyPlane.hpp>
#include <bullet.hpp>
using namespace std;
static bool realTouch(double x1,double y1,double x,double y)
{
    double p,biao=45/38;
    if (x>=x1-2 && x<=x1+2)
    {
        if (y<=y1+10 && y>=y1-50) return true;
        return false;
    }
    y1+=-22;
    if (x<x1-40 || x>x1+40) return false;
    if (y<y1-50 || y>y1) return false;
    if (x<=x1)
    {
        p=y1-(x1-x)*biao;
        if (y>=p) return true;
        return false;
    } else
    {
        p=y1-(x-x1)*biao;
        if (y>=p) return true;
        return false;
    }
    // 62 65 100 20
}
static void deleteEnemy(std::vector <EnemyPlane> &f22)
{
    int i;
    for (i=f22.size()-1;i>=0;i--)
    if (!f22[i].exist)
    {
        f22[i].boomtime--;
        f22[i].boomSprite.setPosition(f22[i].posy-20, f22[i].posx);
        f22[i].boomSprite.setScale((f22[i].boomscale-f22[i].boomtime)/f22[i].boomscale/f22[i].ki, (f22[i].boomscale-f22[i].boomtime)/f22[i].boomscale/f22[i].ki);
        if (f22[i].boomtime<=0 && f22[i].list.size()==0)
        {
            f22.erase(f22.begin()+i);
        }
    }
}
static void touchEnemy(vector <EnemyPlane> &f22,Bullet &myFire)
{
    int i,j;
        for (i=0;i<f22.size();i++)
        if (f22[i].exist)
        {
           for (j=0;j<myFire.list.size();j++)
           if (realTouch(f22[i].posy+62,f22[i].posx+70,myFire.list[j].posy,myFire.list[j].posx))
           {
               f22[i].boomSprite.setPosition(f22[i].posy-20, f22[i].posx);
               f22[i].boomSprite.setScale((f22[i].boomscale-f22[i].boomtime)/f22[i].boomscale/f22[i].ki, (f22[i].boomscale-f22[i].boomtime)/f22[i].boomscale/f22[i].ki);
               myFire.point+=5;
               f22[i].exist=false;
               myFire.list.erase(myFire.list.begin()+j);
               break;
           }
        }
}
#endif /* Touch_hpp */
