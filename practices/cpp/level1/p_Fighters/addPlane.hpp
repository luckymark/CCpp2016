//
//  addPlane.hpp
//  My first app
//
//  Created by macintosh on 16/5/24.
//  Copyright © 2016年 interesting. All rights reserved.
//

#ifndef addPlane_hpp
#define addPlane_hpp
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
// Here is a small helper for you ! Have a look.
#include "ResourcePath.hpp"
#include "MovePlane.hpp"
#include "bullet.hpp"
#include "EnemyPlane.hpp"
#include "Touch.hpp"
#include "health.hpp"
#include "Text.hpp"
#include "F16.hpp"
#include "F35.hpp"
#include <stdio.h>
#include <vector>
static void addF22(vector <EnemyPlane> &f22,int &f22Time,int &f22Limit,int &now)
{
    if (f22Time>f22Limit)
    {
        f22.push_back(EnemyPlane(1,rand()%1441-10,0,2,200));//敌机速度 敌机坐标 子弹速度 开火间隙
        f22Time=0;
    }
}
static void addF16(vector <F16> &f16,int &f16Time,int &f16Limit,int &now)
{
    if (f16Time>f16Limit && now>1)
    {
        f16.push_back(F16(1,rand()%1441-10,0,2,200));
        f16Time=0;
    }
}
static void addF35(vector <F35> &f35,int &f35Time,int &f35Limit,int &now)
{
    if (f35Time>f35Limit && now>2)
    {
        f35.push_back(F35(rand()%1441-10,0,1.2));
        f35Time=0;
    }
}
static void getLimit(int &now,int &f22Limit,int &f16Limit,int &f35Limit)
{
    if (now==1) f22Limit=400;
    if (now==2)
    {
        f22Limit=400;
        f16Limit=400;
    }
    if (now==3)
    {
        f22Limit=400;
        f16Limit=400;
        f35Limit=400;
    }
    if (now==4)
    {
        f22Limit=300;
        f16Limit=300;
        f35Limit=400;
    }
    if (now==5)
    {
        f22Limit=200;
        f16Limit=200;
        f35Limit=400;
    }
    if (now==6)
    {
        f22Limit=200;
        f16Limit=200;
        f35Limit=200;
    }
}
#endif /* addPlane_hpp */
