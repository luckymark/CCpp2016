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
    
}

bool Stack::isFull(){
    if (element[cap-1]!='\0') {
        return 1;
    }else {
        return 0;
    }
    
}



bool Stack::isEmpty(){
    if (element[0]=='\0') {
        return 1;
    }else{
        return 0;
    }
}

void Stack::push(int item){
    for (int i=0;i<cap ; i++) {
        if (element[i]==0) {
            element[i]=item;
            break;
        }
    }
}
void Stack::pop(){
    for (int i=0; i<cap; i++) {
        if (element[i]==0) {
            element[i-1]=0;
            break;
        }
    }
}