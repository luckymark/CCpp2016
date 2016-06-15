//
// Created by Administrator on 2016/6/9.
//

#ifndef P_CIRCUIT_FAN_H
#define P_CIRCUIT_FAN_H
#include <iostream>
#include "SwitchAble.h"

class Fan : public SwitchAble {
public:
    virtual void on() {
        std::cout << "风扇转动";
    }

    virtual void off() {
        std::cout << "风扇停止转动";
    }
};



#endif //P_CIRCUIT_FAN_H
