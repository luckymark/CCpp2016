/**
 * Project Untitled
 */


#ifndef _HEROBULLET_H
#define _HEROBULLET_H

#include "Plane.h"


class HeroBullet:public Plane {
public:
    HeroBullet(const sf::Vector2f&iniPosition=sf::Vector2f(0,0),const sf::Vector2f& iniDirection=sf::Vector2f(0,-1.f));

    virtual void refresh(float);

    virtual void appendToGame();

    virtual void initializeLife();

    virtual void initializeSpeed();

    virtual void initializeSprite();

    virtual void initializeShootElapsed();

    virtual void draw();

    virtual Plane* clone();

    virtual void playBombSound();

    virtual Plane* setCollisonArea();

    virtual sf::Color getLightColor();
    //virtual Plane* setCollisonArea();
};

#endif //_HEROBULLET_H
