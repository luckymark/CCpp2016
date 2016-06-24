//
//  MovePlane.hpp
//  My first app
//
//  Created by macintosh on 16/5/5.
//  Copyright © 2016年 interesting. All rights reserved.
//
#ifndef MovePlane_hpp
#define MovePlane_hpp
#include <stdio.h>
static double posx=920,posy=730;
static double jx,jy;
static double leftlimit=-10,rightlimit=1430,uplimit=0,downlimt=920,planespeed=2;
static bool direction[4];
class MovePlane{
public:
    void left()
    {
        posy+=-planespeed;
        if (posy<leftlimit) posy=leftlimit;
    }
    void right()
    {
        posy+=planespeed;
        if (posy>rightlimit) posy=rightlimit;
    }
    void up()
    {
        posx+=-planespeed;
        if (posx<uplimit) posx=uplimit;
    }
    void down()
    {
        posx+=planespeed;
        if (posx>downlimt) posx=downlimt;
    }
    void clear()
    {
        posx=920;
        posy=730;
        for (int i=0;i<4;i++) direction[i]=false;
    }
};

#endif /* MovePlane_hpp */
