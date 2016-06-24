//
//  Circle.hpp
//  CircleAndPoint
//
//  Created by mac on 16/6/13.
//  Copyright © 2016年 CCPP. All rights reserved.
//

#ifndef Circle_hpp
#define Circle_hpp

#include <stdio.h>
#include "Point.hpp"
#include <iostream>
class Circle{
private:
    Point point;
    double radius;
public:
    Circle(double x,double y,double r);
    void draw();
    void move(std::pair<double,double> vector);
};
#endif /* Circle_hpp */
