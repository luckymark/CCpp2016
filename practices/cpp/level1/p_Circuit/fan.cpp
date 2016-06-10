//
// Created by iam24 on 16/4/25.
//

#include "fan.h"
#include <iostream>
void Fan::on() {
    std::cout<<"风扇开始转动了"<<std::endl;
    return ;
}

void Fan::off() {
    std::cout<<"风扇停止转动了"<<std::endl;
}