//
// Created by Administrator on 2016/6/9.
//
#include "SwitchAble.h"
extern list<SwitchAble> binded;

void Button::bind(SwitchAble target) {
    binded.push_back(target);
}

void Button::on(){
    for(list &s :binded){
        s.on();
    }
}

void Button::on(){
    for(list &s : binded){
        s.off();
    }
}