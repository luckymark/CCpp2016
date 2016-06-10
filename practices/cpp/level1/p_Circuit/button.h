//
// Created by iam24 on 16/4/25.
//

#ifndef BUTTON_BUTTON_H
#define BUTTON_BUTTON_H

#include "base.h"
class Button {
public:
    void on();
    void off();
    void bind(Base *a);
private:
    Base * x;
};


#endif //BUTTON_BUTTON_H
