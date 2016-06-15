//
//  SecondaryObject.hpp
//  plane
//
//  Created by mac on 16/5/7.
//  Copyright © 2016年 CCPP. All rights reserved.
//

#ifndef SecondaryObject_hpp
#define SecondaryObject_hpp
#include "Object.hpp"
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <stdio.h>
#include <stdio.h>
class SecondaryObject : public Object {
  public:
    double getOccurrenceTime();
    ~SecondaryObject(){
        target.reset();
    }
    virtual void move();
    bool out();
    void setTarget(std::shared_ptr<Object> target);
  protected:
    double initialVelocity;
    double acceleration = 0;
    sf::Vector2f unitVector;
    sf::Clock occurrenceTime;
    std::weak_ptr<Object> target;
};
#endif /* SecondaryObject_hpp */
