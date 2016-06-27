#ifndef _HERO_H
#define _HERO_H

#include "Plane.h"
#include <SFML/Graphics.hpp>

class Hero: public Plane {
public:
    static Hero* instance(const sf::Vector2f&);

    virtual void fire();

    virtual void beHited(int);

    virtual void refresh(float);

    virtual float getBottom();

    virtual void changeStatus();

    virtual void appendToGame();

    virtual void shootBullet();

    virtual void initializeBullet();

    virtual void initializeLife();

    virtual void initializeSpeed();

    virtual void initializeSprite();

    virtual void initializeShootElapsed();

    virtual Plane* clone();

    virtual void playBombSound();

    virtual void draw();

    virtual Plane* setCollisonArea();

    virtual void useSkill();

    virtual void intensifyFire();

    virtual void initializeShootType();
protected:
    Hero(const sf::Vector2f&);
private:
    static Hero* _instance;
    int _flash,maxFlashTime;
    int shootType=0;
};

#endif //_HERO_H
