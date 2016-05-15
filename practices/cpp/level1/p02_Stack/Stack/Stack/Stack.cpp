//
//  Stack.cpp
//  Queue
//
//  Created by 陈浩贤 on 16/3/28.
//  Copyright © 2016年 陈浩贤. All rights reserved.
//

#include "Stack.hpp"

Stack::Stack (int capbility){
    element=new int(capbility);
    cap=capbility;
    current=0;
}

bool Stack::isFull(){
    return element[cap-1]!='\0';
}



bool Stack::isEmpty(){
    return element[0]!='\0';
}

void Stack::push(int item){
    element[current]=item;
    current++;
}
void Stack::pop(){
    element[current]='\0';
    current--;
}