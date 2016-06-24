//
//  Point.hpp
//  CircleAndPoint
//
//  Created by mac on 16/6/13.
//  Copyright © 2016年 CCPP. All rights reserved.
//

#ifndef Point_hpp
#define Point_hpp

#include <stdio.h>
#include <iostream>
class Point{
private:
    std::pair<double,double> point;
public:
    void setPoint(double x,double y);
    void showPoint();
    void move(std::pair<double,double> vector);
};
#endif /* Point_hpp */
