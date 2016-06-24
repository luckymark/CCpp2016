//
//  health.hpp
//  My first app
//
//  Created by macintosh on 16/5/10.
//  Copyright © 2016年 interesting. All rights reserved.
//

#ifndef health_hpp
#define health_hpp
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "ResourcePath.hpp"
#include <stdio.h>
#include <vector>
#include "EnemyPlane.hpp"
#include "F16.hpp"
#include "F35.hpp"
using namespace std;
class health{
public:
    int boomTime,life,bloodStain,time,deadTime;
    double boomScale,ki;
    sf::Texture texture[4];
    sf::Sprite sprite[4];
    sf::Sprite boomSprite;
    health()
    {
        int i;
        life=3;
        bloodStain=4;
        time=0;
        deadTime=0;
        texture[0].loadFromFile(resourcePath() + "血量1.png");
        texture[1].loadFromFile(resourcePath() + "血量2.png");
        texture[2].loadFromFile(resourcePath() + "血量3.png");
        texture[3].loadFromFile(resourcePath() + "血量4.png");
        boomSprite.setTexture(F35BoomTexture);
        ki=1;
        boomTime=10;
        boomScale=boomTime+10;
        for (i=0;i<4;i++)
        {
            sprite[i].setTexture(texture[i]);
            sprite[i].setPosition(7,7);
        }
    }
    void clear()
    {
        int i;
        life=3;
        bloodStain=4;
        time=0;
        deadTime=0;
    }
    double abs(double x)
    {
        if (x>=0) return x;
        return -x;
    }
    bool realtouch(double x,double y,double x1,double y1)
    {
        double biao=52/32,p;
        if (x1>=x-2 && x1<=x+2) y=y-3;
        if (x1<x-32 || x1>x+32) return false;
        if (y1<y || y1>y+52) return false;
        p=y+this->abs(x-x1)*biao;
        if (y1<p) return false;
        return true;
        
    }
    
    
    
    void touchBullet(double &posy,double &posx,vector <EnemyPlane> &f22)
    {
        int i,j;
        if (time!=0)
        {
            for (i=0;i<f22.size();i++)
            {
                for (j=f22[i].list.size()-1;j>=0;j--)
                if (this->realtouch(posy+42,posx,f22[i].list[j].posy,f22[i].list[j].posx))
                {
                    f22[i].list.erase(f22[i].list.begin()+j);
                }
            }
            return ;
        }
        for (i=0;i<f22.size();i++)
        {
            for (j=0;j<f22[i].list.size();j++)
                if (this->realtouch(posy+42,posx,f22[i].list[j].posy,f22[i].list[j].posx))
                {
                    break;
                }
                if (j<f22[i].list.size())
                {
                    bloodStain--;
                    if (bloodStain==0)
                    {
                        life--;
                        deadTime=400;
                        bloodStain=4;
                        jx=posx;
                        jy=posy;
                        posx=920;
                        posy=730;
                    }
                    time=600;
                    f22[i].list.erase(f22[i].list.begin()+j);
                    break;
                }
        }
    }
   int touchLine(double x,double y,double x1,double y1,double x2,double y2)
    {
        if (y1==y2) return 0;
        if (x1+(y-y1)*(x1-x2)/(y1-y2)>x && (y1-y)*(y2-y)<0) return 1;
        return 0;
    }
   bool can(double x,double y,double x1,double y1,double x2,double y2,double x3,double y3)
    {
        int all;
    all=this->touchLine(x,y,x1,y1,x2,y2)+this->touchLine(x,y,x2,y2,x3,y3)+this->touchLine(x,y,x3,y3,x1,y1);
        if (all%2==1) return true;
        return false;
    }
    bool inside(double ex,double ey,double x,double y)
    {
        int i;
        double bx=32.0/9.0,by=52.0/9.0;
        for (i=0;i<10;i++)
        if (this->can(x-bx*i,y+by*i,ex,ey,ex-40,ey-50,ex+40,ey-50)) return true;
        for (i=0;i<10;i++)
        if (this->can(x+bx*i,y+by*i,ex,ey,ex-40,ey-50,ex+40,ey-50)) return true;
        for (i=0;i<10;i++)
        if (this->can(x-32+bx*i*2,y+52,ex,ey,ex-40,ey-50,ex+40,ey-50)) return true;
        return false;
        
    }
    void touchPlane(double &posy,double &posx,vector <EnemyPlane> &f22)
    {
        int i;
        for (i=0;i<f22.size();i++)
        if (f22[i].exist && this->inside(f22[i].posy+62,f22[i].posx+70,posy+42,posx)) break;
        if (i<f22.size())
        {
            f22[i].exist=false;
            bloodStain--;
            f22[i].boomSprite.setPosition(f22[i].posy-20, f22[i].posx);
            f22[i].boomSprite.setScale((f22[i].boomscale-f22[i].boomtime)/f22[i].boomscale/f22[i].ki, (f22[i].boomscale-f22[i].boomtime)/f22[i].boomscale/f22[i].ki);

            if (bloodStain==0)
            {
                life--;
                deadTime=400;
                bloodStain=4;
                jx=posx;
                jy=posy;
                posx=920;
                posy=730;
            }
            time=600;
        }
    }
    
    void touchF16Fire(double &posy,double &posx,vector <F16> &f16)
    {
        int i,j;
        if (time!=0)
        {
            for (i=0;i<f16.size();i++)
            {
                for (j=f16[i].list.size()-1;j>=0;j--)
                    if (this->realtouch(posy+42,posx,f16[i].list[j].posy,f16[i].list[j].posx))
                    {
                        f16[i].list.erase(f16[i].list.begin()+j);
                    }
            }
            return ;
        }
        for (i=0;i<f16.size();i++)
        {
            for (j=0;j<f16[i].list.size();j++)
                if (this->realtouch(posy+42,posx,f16[i].list[j].posy,f16[i].list[j].posx))
                {
                    break;
                }
            if (j<f16[i].list.size())
            {
                bloodStain--;
                if (bloodStain==0)
                {
                    life--;
                    deadTime=400;
                    bloodStain=4;
                    jx=posx;
                    jy=posy;
                    posx=920;
                    posy=730;
                }
                time=600;
                f16[i].list.erase(f16[i].list.begin()+j);
                break;
            }
        }
    }
    
    bool insideF16(double ex,double ey,double x,double y)
    {
        int i;
        double bx=32.0/9.0,by=52.0/9.0;
        for (i=0;i<10;i++)
            if (this->can(x-bx*i,y+by*i,ex,ey,ex-20,ey-52,ex+20,ey-52)) return true;
        for (i=0;i<10;i++)
            if (this->can(x+bx*i,y+by*i,ex,ey,ex-20,ey-52,ex+20,ey-52)) return true;
        for (i=0;i<10;i++)
            if (this->can(x-32+bx*i*2,y+52,ex,ey,ex-20,ey-52,ex+20,ey-52)) return true;
        return false;
        
    }
    
    void touchF16Plane(double &posy,double &posx,vector <F16> &f16)
    {
        int i;
        for (i=0;i<f16.size();i++)
            if (f16[i].exist && this->insideF16(f16[i].posy+20,f16[i].posx+52,posy+42,posx)) break;
        if (i<f16.size())
        {
            f16[i].exist=false;
            bloodStain--;
            f16[i].boomSprite.setPosition(f16[i].posy-20, f16[i].posx);
            f16[i].boomSprite.setScale((f16[i].boomscale-f16[i].boomtime)/f16[i].boomscale/f16[i].ki, (f16[i].boomscale-f16[i].boomtime)/f16[i].boomscale/f16[i].ki);
            if (bloodStain==0)
            {
                life--;
                deadTime=400;
                bloodStain=4;
                jx=posx;
                jy=posy;
                posx=920;
                posy=730;
            }
            time=600;
        }
    }
    void touchF35Plane(sf::Sprite sprite,vector <F35> &f35)
    {
        int i;
        for (i=0;i<f35.size();i++)
        if (f35[i].exsit && f35[i].sprite.getGlobalBounds().intersects(sprite.getGlobalBounds()))
        {
            f35[i].exsit=false;
            f35[i].boomSprite.setPosition(f35[i].posy-20, f35[i].posx);
             f35[i].boomSprite.setScale((f35[i].boomscale-f35[i].boomtime)/f35[i].boomscale/f35[i].ki, (f35[i].boomscale-f35[i].boomtime)/f35[i].boomscale/f35[i].ki);
            bloodStain-=2;
            if (bloodStain<=0)
            {
                life--;
                deadTime=400;
                bloodStain=4;
                jx=posx;
                jy=posy;
                posx=920;
                posy=730;
            }
            time=600;
            return;
        }
    }
    void updateLife(sf::Text &text)
    {
        text.setCharacterSize(20);
        text.setString(to_string(life));
        text.setPosition(50,102);
    }
};
#endif /* health_hpp */
