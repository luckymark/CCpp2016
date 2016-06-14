//
// Created by Administrator on 2016/6/9.
//

#ifndef P_CIRCUIT_BUTTON_H
#define P_CIRCUIT_BUTTON_H
#include "SwitchAble.h"

class Button{
public:
    void bind(SwitchAble target);
    void on();
    void off();

private:
    
};


#endif //P_CIRCUIT_BUTTON_H
