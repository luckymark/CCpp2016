//
// Created by Administrator on 2016/6/9.
//
#include <iostream>
#include <list>
#include "Door.h"
#include "Fan.h"
#include "Button.h"
#include "SwitchAble.h"


int main() {
    Button button;
    Fan fan;
    Door door;
    static list<SwitchAble> binded;

    button.bind(fan);
    button.on(); //风扇开始转动
    button.off(); //风扇停止转动

    button.bind(door);
    button.on(); //开门
    button.off(); //关门

    return 0;
}