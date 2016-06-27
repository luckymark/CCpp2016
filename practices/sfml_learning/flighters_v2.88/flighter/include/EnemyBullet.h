/**
 * Project Untitled
 */


#ifndef _ENEMYBULLET_H
#define _ENEMYBULLET_H

#include "Plane.h"


class EnemyBullet: public Plane {
public:

    EnemyBullet(const sf::Vector2f&iniPosition=sf::Vector2f(0,0),const sf::Vector2f& iniDirection=sf::Vector2f(0,1.f));

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

    Plane* setDirection(const sf::Vector2f&);
};

#endif //_ENEMYBULLET_H
