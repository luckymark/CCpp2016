//
// Created by iam24 on 16/4/25.
//

#include "button.h"

void Button::on()
{
    x->on();
}

void Button::off() {
    x->off();
}

void Button::bind(Base *a) {
    x = a;
}