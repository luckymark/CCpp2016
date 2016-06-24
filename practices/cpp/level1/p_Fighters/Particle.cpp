//
//  Particle.cpp
//  plane
//
//  Created by mac on 16/5/30.
//  Copyright © 2016年 CCPP. All rights reserved.
//

#include "Particle.hpp"
#include "Stage.hpp"
#include "Texture.hpp"
#include <Stage.hpp>
#include <cmath>
void Particle::creatParticle(sf::Vector2f position) {
    for (double i = 0; i <= 2 * M_PI; i += M_PI_4) {
        Stage::getInstance()->creatParticle(
            new Particle(position, sf::Vector2f(cos(i), sin(i))));
    }
}
Particle::Particle(sf::Vector2f position, sf::Vector2f unitVector) {
    last = 0.3;
    setTexture(Texture::PARTICLE);
    setPosition(position);
    initialVelocity = 10.0;
    this->unitVector = unitVector;
}