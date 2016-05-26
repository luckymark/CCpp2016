/**
 * Project Untitled
 */


#ifndef _HERO_H
#define _HERO_H

#include "Plane.h"
#include <SFML/Graphics.hpp>

class Hero: public Plane {
public:
    static Hero* instance(const sf::Vector2f&);

    virtual void fire();

    virtual void beHited();

    virtual void refresh(float);

    virtual float getBottom();

    virtual void changeStatus();

    virtual void appendToGame();

    virtual void shootBullet();

    virtual void initializeLife();

    virtual void initializeSpeed();

    virtual void initializeSprite();

    virtual void initializeShootElapsed();

    virtual Plane* clone();

    virtual void playBombSound();

    virtual bool isBeHited();

    virtual void recoverNormal();
protected:
    Hero(const sf::Vector2f&);
private:
    static Hero* _instance;
    bool _isBeHited;
};

#endif //_HERO_H
