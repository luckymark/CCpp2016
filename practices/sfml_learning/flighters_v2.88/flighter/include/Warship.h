/**
 * Project Untitled
 */


#ifndef _WARSHIP_H
#define _WARSHIP_H

#include "Plane.h"
#include <SFML/Graphics.hpp>

class Warship: public Plane {
public:
    Warship(sf::Vector2f iniPosition = _iniPosition,sf::Vector2f iniDirection = _iniDirection);

    void fire();

    void initializeSpeed();

    void initializeLife();

    void initializeSprite();

    void initializeShootElapsed();

    void refresh(float);

    Plane* clone();

    Plane* setCollisonArea();

    void changeStatus();

    void draw();

    void playFlyingSound();

    void playBombSound();

    void initializeBullet();

    void shootBullet();
private:
    static sf::Vector2f _iniPosition;
    static sf::Vector2f _iniDirection;
    static bool isPlayFlyingSound;
};

#endif //_WARSHIP_H
