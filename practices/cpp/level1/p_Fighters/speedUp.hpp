//
//  speedUp.hpp
//  plane
//
//  Created by mac on 16/5/10.
//  Copyright © 2016年 CCPP. All rights reserved.
//

#ifndef speedUp_hpp
#define speedUp_hpp
#include "Hero.hpp"
#include "Pickup.hpp"
#include "Texture.hpp"
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <stdio.h>
class SpeedUp : public Pickup {
    void use() { Hero::getInstance()->speedUp(); }
public:
    SpeedUp(double PostionX, double PostionY) {
        initialVelocity = 2.5;
        acceleration = 0;
        unitVector.x = -1;
        unitVector.y = 0;
        setTexture(Texture::PICKUP[2]);
        setPosition(PostionX, PostionY);
        deviation.x = 40;
        deviation.y = 40;
        radius = 40;
    }
};
#endif /* speedUp_hpp */
