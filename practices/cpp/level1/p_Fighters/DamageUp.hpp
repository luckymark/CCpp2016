//
//  DamageUp.hpp
//  plane
//
//  Created by mac on 16/5/10.
//  Copyright © 2016年 CCPP. All rights reserved.
//

#ifndef DamageUp_hpp
#define DamageUp_hpp
#include "Hero.hpp"
#include "Pickup.hpp"
#include "Texture.hpp"
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <stdio.h>
class DamageUp : public Pickup {
    void use() { Hero::getInstance()->damageUp(); }
public:
    DamageUp(double PositionX, double PositionY) {
        initialVelocity = 2.5;
        acceleration = 0;
        unitVector.x = -1;
        unitVector.y = 0;
        setTexture(Texture::PICKUP[3]);
        setPosition(PositionX, PositionY);
        deviation.x = 40;
        deviation.y = 40;
        radius = 40;
    }
};
#endif /* DamageUp_hpp */
