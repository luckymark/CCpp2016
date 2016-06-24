//
//  AutoFire.hpp
//  plane
//
//  Created by mac on 16/5/20.
//  Copyright © 2016年 CCPP. All rights reserved.
//

#ifndef AutoFire_hpp
#define AutoFire_hpp
#include "Hero.hpp"
#include "Pickup.hpp"
#include "Texture.hpp"
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <stdio.h>
class AutoFire : public Pickup {
    void use() { Hero::getInstance()->autoFire(); }
public:
    AutoFire(double PositionX, double PositionY) {
        initialVelocity = 2.5;
        acceleration = 0;
        unitVector.x = -1;
        unitVector.y = 0;
        setTexture(Texture::PICKUP[4]);
        setPosition(PositionX, PositionY);
        deviation.x = 40;
        deviation.y = 40;
        radius = 40;
    }
};
#endif /* AutoFire_hpp */
