//
//  Timer.cpp
//  plane
//
//  Created by mac on 16/5/21.
//  Copyright © 2016年 CCPP. All rights reserved.
//

#include "Timer.hpp"
void Timer::restart() {
    walked = 0;
    start();
}
void Timer::start() {
    sf::Clock::restart();
    isWalk = true;
}
void Timer::pause() {
    isWalk = false;
    walked += sf::Clock::getElapsedTime().asSeconds();
}
double Timer::getTime() {
    double res = walked;
    if (isWalk) {
        res += sf::Clock::getElapsedTime().asSeconds();
    }
    return res;
}