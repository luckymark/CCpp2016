//
//  Point.cpp
//  CircleAndPoint
//
//  Created by mac on 16/6/13.
//  Copyright © 2016年 CCPP. All rights reserved.
//

#include "Point.hpp"
void Point::setPoint(double x, double y){
    point = std::make_pair(x,y);
}
void Point::showPoint(){
    std::cout<<point.first<<" "<<point.second<<std::endl;
}
void Point::move(std::pair<double,double> vector){
    point.first+=vector.first;
    point.second+=vector.second;
}
