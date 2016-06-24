//
//  Cloud.hpp
//  plane
//
//  Created by mac on 16/6/1.
//  Copyright © 2016年 CCPP. All rights reserved.
//

#ifndef Cloud_hpp
#define Cloud_hpp
#include "Effect.hpp"
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <stdio.h>
class Cloud : public Effect {
  public:
    void move();
    Cloud(sf::Vector2f position);
};
#endif /* Cloud_hpp */
