#ifndef BOMBUFO_H
#define BOMBUFO_H


#include "Plane.h"
#include <SFML/Graphics.hpp>
class BombUfo : public Plane
{
public:
    BombUfo(const sf::Vector2f&iniPosition=sf::Vector2f(0,-107),const sf::Vector2f& iniDirection=sf::Vector2f(0,1.f));;

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
#endif // BOMBUFO_H
