//
//  Particle.hpp
//  plane
//
//  Created by mac on 16/5/30.
//  Copyright © 2016年 CCPP. All rights reserved.
//

#ifndef Particle_hpp
#define Particle_hpp
#include "Effect.hpp"
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <stdio.h>
class Particle:public Effect{
    private:
    Particle(sf::Vector2f position,sf::Vector2f unitVector);
public:
    static void creatParticle(sf::Vector2f position);
};
#endif /* Particle_hpp */
