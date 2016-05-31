/**
 * Project Untitled
 */


#ifndef _WARPLANE_H
#define _WARPLANE_H

#include "Plane.h"
#include <SFML/Graphics.hpp>

class Warplane: public Plane {
public:
    Warplane(sf::Vector2f iniPosition = _iniPosition,sf::Vector2f iniDirection = _iniDirection);

    void fire();

    void initializeSpeed();

    void initializeLife();

    void initializeSprite();

    void initializeShootElapsed();

    void refresh(float);

    void shootBullet();

    Plane* clone();

    Plane* setCollisonArea();

    void playBombSound();

    void draw();
private:
    static sf::Vector2f _iniPosition;
    static sf::Vector2f _iniDirection;
};

#endif //_WARPLANE_H
