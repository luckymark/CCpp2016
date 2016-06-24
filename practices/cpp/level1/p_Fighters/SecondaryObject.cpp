//
//  SecondaryObject.cpp
//  plane
//
//  Created by mac on 16/5/7.
//  Copyright © 2016年 CCPP. All rights reserved.
//

#include "SecondaryObject.hpp"
#include <cmath>
double SecondaryObject::getOccurrenceTime(){
    return occurrenceTime.getElapsedTime().asSeconds();
}
void SecondaryObject::setTarget(std::shared_ptr<Object> target){
    this->target=std::weak_ptr<Object>(target);
}
void SecondaryObject::move() {
    if (!target.expired()) {
        unitVector = getUnitVector(this, target.lock().get());
    }
    Object::move((initialVelocity +
                  occurrenceTime.getElapsedTime().asSeconds() * acceleration) *
                     unitVector.x,
                 (initialVelocity +
                  occurrenceTime.getElapsedTime().asSeconds() * acceleration) *
                     unitVector.y);
}
bool SecondaryObject::out() {
    return (getPosition().x >= 1800 + 2 * radius ||
            getPosition().x < -2 * radius || getPosition().y < -2 * radius ||
            getPosition().y >= 1200 + radius);
}