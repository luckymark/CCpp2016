//
//  player.cpp
//  SFML-PLANE
//
//  Created by iam24 on 16/5/8.
//  Copyright © 2016年 iam24. All rights reserved.
//

#include "player.hpp"
#include <SFML/Graphics.hpp>
#include "ResourcePath.hpp"
#include <cmath>
#include "bullet.hpp"
#include "Texture.hpp"
Player::Player(double speed)
{
    player_speed = speed;
    sprite.setTexture(Texture::player_texture);
    sprite.setPosition(425,1200);
    
}




