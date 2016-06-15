#ifndef BulletTwo_hpp
#define BulletTwo_hpp

#include "Hero.hpp"
#include "Object.hpp"
#include "SecondaryObject.hpp"
#include "Texture.hpp"
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <stdio.h>
class BulletTwo : public SecondaryObject {
  public:
    BulletTwo(double positionX, double positionY) {
        initialVelocity = 10.0;
        acceleration = 0;
        setPosition(positionX, positionY);
        deviation.x = 50;
        deviation.y = 50;
        radius = 25;
        unitVector = getUnitVector(this, Hero::getInstance());
        setTexture(Texture::ENEMY_BULLET);
    };
};
#endif /* BulletTwo_hpp */
