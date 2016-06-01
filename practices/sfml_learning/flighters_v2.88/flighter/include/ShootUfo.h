#ifndef SHOOTUFO_H
#define SHOOTUFO_H

#include "Plane.h"
#include <SFML/Graphics.hpp>
class ShootUfo : public Plane
{
public:
    ShootUfo(const sf::Vector2f&iniPosition = sf::Vector2f(0,-88),const sf::Vector2f& iniDirection=sf::Vector2f(0,1.f));;

    virtual void refresh(float);

    virtual void appendToGame();

    virtual void initializeLife();

    virtual void initializeSpeed();

    virtual void initializeSprite();

    virtual void initializeShootElapsed();

    virtual void draw();

    virtual Plane* clone();

    virtual void playBombSound();

    virtual void getSkill(Plane*);

    virtual Plane* setCollisonArea();
private:
};

#endif // UFO_H
