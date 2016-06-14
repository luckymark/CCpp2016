//
// Created by Administrator on 2016/6/9.
//
#include <iostream>
#include "Door.h"
#include "Fan.h"
#include "Button.h"

int main() {
    Button button;
    Fan fan;
    Door door;
    //Bulb bulb;

    button.bind(fan);
    button.on(); //风扇开始转动
    button.off(); //风扇停止转动

    //button.bind(bulb);
    //button.on(); //电灯亮
    //button.off(); //电灯灭

    button.bind(door);
    button.on(); //开门
    button.off(); //关门

    return 0;
}