//
//  Circle.cpp
//  CircleAndPoint
//
//  Created by mac on 16/6/13.
//  Copyright © 2016年 CCPP. All rights reserved.
//

#include "Circle.hpp"
Circle::Circle(double x,double y,double r){
    radius = r;
    point.setPoint(x, y);
}
void Circle::draw(){
    std::cout<<"center :";
    point.showPoint();
    std::cout<<"radius :"<<radius<<std::endl;
}
void Circle::move(std::pair<double,double> vector){
    point.move(vector);
}
