//
//  Pickup.hpp
//  plane
//
//  Created by mac on 16/5/10.
//  Copyright © 2016年 CCPP. All rights reserved.
//

#ifndef Pickup_hpp
#define Pickup_hpp
#include "SecondaryObject.hpp"
#include <Hero.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <stdio.h>
class Pickup : public SecondaryObject {
  public:
    void move() {
        Object::move(-2.5, 0);
        if (Hero::getInstance()->getMagnetic()) {
            double from = getPosition().y + deviation.y;
            double to = Hero::getInstance()->getPosition().y +
                        Hero::getInstance()->getDeviation().y;
            if (to > from) {
                Object::move(0, 0.5);
            }
            if (to < from) {
                Object::move(0, -0.5);
            }
        }
    }

  public:
    virtual void use() = 0;
};
#endif /* Pickup_hpp */
