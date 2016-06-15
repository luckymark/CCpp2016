//
// Created by Administrator on 2016/6/9.
//

#ifndef P_CIRCUIT_DOOR_H
#define P_CIRCUIT_DOOR_H
#include <iostream>
#include "SwitchAble.h"

class Door : public SwitchAble {
public:
    virtual void on() {
        std::cout << "开门";
    }

    virtual void off() {
        std::cout << "关门";
    }
};


#endif //P_CIRCUIT_DOOR_H
