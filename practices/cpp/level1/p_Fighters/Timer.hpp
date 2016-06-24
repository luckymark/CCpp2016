//
//  Timer.hpp
//  plane
//
//  Created by mac on 16/5/21.
//  Copyright © 2016年 CCPP. All rights reserved.
//

#ifndef Timer_hpp
#define Timer_hpp
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <stdio.h>
class Timer : private sf::Clock {
  private:
    double walked;
    bool isWalk;

  public:
    void restart();
    void start();
    void pause();
    double getTime();
};
#endif /* Timer_hpp */
