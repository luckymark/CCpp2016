//
//  Cloud.cpp
//  plane
//
//  Created by mac on 16/6/1.
//  Copyright © 2016年 CCPP. All rights reserved.
//

#include "Cloud.hpp"
#include "Texture.hpp"
Cloud::Cloud(sf::Vector2f position) {
    last = 1.0;
    setTexture(Texture::CLOUD);
    setPosition(position);
}
void Cloud::move() {
    setColor(sf::Color(255, 255, 255, 255 - 255 * getOccurrenceTime()));
}