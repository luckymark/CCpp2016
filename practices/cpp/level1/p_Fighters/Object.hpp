//
//  Object.hpp
//  plane
//
//  Created by mac on 16/5/7.
//  Copyright © 2016年 CCPP. All rights reserved.
//

#ifndef Object_hpp
#define Object_hpp
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
class Object : public sf::Sprite {
  protected:
    sf::Vector2i deviation;
    int radius;

  public:
    sf::Vector2i getDeviation();
    friend sf::Vector2f getUnitVector(Object *source, Object *target);
    friend bool touch(Object *first, Object *second);
    friend sf::Vector2f getTouch(Object *first, Object *second);
};
#endif /* Object_hpp */
