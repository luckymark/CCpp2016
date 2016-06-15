#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include "EnemyPlane.h"
#include "Sprites.h"
#include <cstdlib>

EnemyPlane::EnemyPlane(int flag)
{
    this->flag=flag;
    FireCounter=0;
    ResetCounter=0;
    ResetFrequence=3;
    y=0;
    DestoryFlag=0;
    if (flag==1)
    {
        EnemyPlaneSprite=Sprites::enemy1;
        vx=0;
        vy=1;
        health=1;
        FireFrequence=30;
    }
    if (flag==2)
    {
        EnemyPlaneSprite=Sprites::enemy2;
        vx=0;
        vy=0.75;
        health=2;
        FireFrequence=45;
    }
    if (flag==3)
    {
        EnemyPlaneSprite=Sprites::enemy3_n2;
        vx=0;
        vy=0.5;
        health=3;
        FireFrequence=60;
    }
    x=rand()%(400-(int)EnemyPlaneSprite.getGlobalBounds().width);
}

bool EnemyPlane::fire()
{
    FireCounter=(FireCounter+1)%FireFrequence;
    if (FireCounter==0)
    {
        return true;
    }
    return false;
}

void EnemyPlane::DecreaseHealth()
{
    health--;
}

void EnemyPlane::move()
{
    if (health<=0)
    {
        return;
    }
    x=x+vx;
    y=y+vy;
    EnemyPlaneSprite.setPosition(x,y);
}

void EnemyPlane::ResetSprite()
{
    if (health>0)
    {
            if (flag==2){
                    if (health==1) EnemyPlaneSprite=Sprites::enemy2_hit;
            }
            if (flag==3){
                    if (health==2)
                    {
                        EnemyPlaneSprite=Sprites::enemy3_n1;
                    }
                    if (health==1)
                    {
                        EnemyPlaneSprite=Sprites::enemy3_hit;
                    }

            }
    }
    else
        {
            ResetCounter++;
            if (flag==1)
            {
                    if (ResetCounter/ResetFrequence>=1)
                    {
                        EnemyPlaneSprite=Sprites::enemy1_down1;
                    }

                    if (ResetCounter/ResetFrequence>=2)
                    {
                        EnemyPlaneSprite=Sprites::enemy1_down2;
                    }

                    if (ResetCounter/ResetFrequence>=3)
                    {
                        EnemyPlaneSprite=Sprites::enemy1_down3;
                    }

                    if (ResetCounter/ResetFrequence>=4)
                    {
                        EnemyPlaneSprite=Sprites::enemy1_down4;
                    }

                    if (ResetCounter/ResetFrequence>=5)
                    {
                        DestoryFlag=1;
                    }

            }
            if (flag==2)
            {
                    if (ResetCounter/ResetFrequence>=1)
                    {
                        EnemyPlaneSprite=Sprites::enemy2_down1;
                    }

                    if (ResetCounter/ResetFrequence>=2)
                    {
                        EnemyPlaneSprite=Sprites::enemy2_down2;
                    }

                    if (ResetCounter/ResetFrequence>=3)
                    {
                        EnemyPlaneSprite=Sprites::enemy2_down3;
                    }

                    if (ResetCounter/ResetFrequence>=4)
                    {
                        EnemyPlaneSprite=Sprites::enemy2_down4;
                    }

                    if (ResetCounter/ResetFrequence>=5)
                    {
                        DestoryFlag=1;
                    }

            }
            if (flag==3)
            {
                    if (ResetCounter/ResetFrequence>=1)
                    {
                        EnemyPlaneSprite=Sprites::enemy3_down1;
                    }

                    if (ResetCounter/ResetFrequence>=2)
                    {
                        EnemyPlaneSprite=Sprites::enemy3_down2;
                    }

                    if (ResetCounter/ResetFrequence>=3)
                    {
                        EnemyPlaneSprite=Sprites::enemy3_down3;
                    }

                    if (ResetCounter/ResetFrequence>=4)
                    {
                        EnemyPlaneSprite=Sprites::enemy3_down4;
                    }

                    if (ResetCounter/ResetFrequence>=5)
                    {
                        EnemyPlaneSprite=Sprites::enemy3_down5;
                    }

                    if (ResetCounter/ResetFrequence>=6)
                    {
                        EnemyPlaneSprite=Sprites::enemy3_down6;
                    }

                    if (ResetCounter/ResetFrequence>=7)
                    {
                        DestoryFlag=1;
                    }

            }
    }
    EnemyPlaneSprite.setPosition(x,y);
}

int EnemyPlane::GetFlag()
{
    return flag;
}

int EnemyPlane::GetHealth()
{
    return health;
}

bool EnemyPlane::IsOut()
{
    if (y>600)
    {
        return true;
    }

    return false;
}

bool EnemyPlane::IsDestoryed()
{
    return DestoryFlag;
}

sf::Sprite EnemyPlane::GetSprite()
{
    return EnemyPlaneSprite;
}
