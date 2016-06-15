//
//  Object.cpp
//  plane
//
//  Created by mac on 16/5/7.
//  Copyright © 2016年 CCPP. All rights reserved.
//

#include "Object.hpp"
#include <cmath>
sf::Vector2i Object::getDeviation() { return deviation; }
sf::Vector2f getUnitVector(Object *source, Object *target) {
    sf::Vector2f unitVector;
    unitVector.x = -source->getPosition().x - source->deviation.x +
                   target->getPosition().x + target->deviation.x;

    unitVector.y = -source->getPosition().y - source->deviation.y +
                   target->getPosition().y + target->deviation.y;
    double step =
        sqrt(unitVector.x * unitVector.x + unitVector.y * unitVector.y);
    unitVector.x /= step;
    unitVector.y /= step;
    return unitVector;
}
double sqr(double number) { return number * number; }
bool touch(Object *first, Object *second) {
    return (sqr(first->getPosition().x + first->deviation.x -
                second->getPosition().x - second->deviation.x) +
                sqr(first->getPosition().y + first->deviation.y -
                    second->getPosition().y - second->deviation.y) <=
            sqr(first->radius + second->radius));
}
sf::Vector2f getTouch(Object *first, Object *second) {
    sf::Vector2f from = getUnitVector(first, second);
    from.x *= first->radius;
    from.y *= first->radius;
    from += first->getPosition();
    from.x += first->deviation.x;
    from.y += first->deviation.y;
    return from;
}
