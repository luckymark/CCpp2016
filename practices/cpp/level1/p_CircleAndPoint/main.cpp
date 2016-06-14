//
//  main.cpp
//  CircleAndPoint
//
//  Created by mac on 16/6/13.
//  Copyright © 2016年 CCPP. All rights reserved.
//

#include <iostream>
#include "Circle.hpp"
int main(int argc, const char *argv[]) {
    Circle circle(1,2,3);
    circle.draw();
    circle.move(std::make_pair(-1, -5));
    circle.draw();
    return 0;
}
