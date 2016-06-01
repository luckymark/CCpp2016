//
//  Stack.cpp
//  Stack
//
//  Created by Ferris on 16/6/1.
//  Copyright © 2016年 Ferris. All rights reserved.
//

#include "Stack.hpp"
#define BLOCK_SIZE 16

Stack::Stack(){
    data = new int[BLOCK_SIZE];
    s_capacity = BLOCK_SIZE;
    s_size = 0;
}

Stack::~Stack(){
    
}

void Stack::push(int num){
    s_size += 1;
    if(s_size >= s_capacity){
        //Automatic expand the internal data field when full
        expand();
    }
    data[s_size-1] = num;
}

int Stack::pop(){
    if((s_capacity - s_size) % BLOCK_SIZE >= 1){
        //Shrink the data field to save memory
        shrink();
    }
    s_size -= 1;
    return data[s_size];
}

bool Stack::isEmpty(){
    return (s_size==0);
}

int Stack::size(){
    return s_size;
}

void Stack::expand(){
    int *temp = new int[s_size];
    //Copy previous array
    for(int i=0; i<=s_size-1; i++){
        temp[i] = data[i];
    }
    data = new int[s_capacity + BLOCK_SIZE];
    for(int i=0; i<=s_size-1; i++){
        data[i] = temp[i];
    }
    s_capacity += BLOCK_SIZE;
    delete temp;
}

void Stack::shrink(){
    // To prevent overflow
    if(s_size > (s_capacity - BLOCK_SIZE)){
        return;
    }
    int *temp = new int[s_size];
    //Copy previous array
    for(int i=0; i<=s_size-1; i++){
        temp[i] = data[i];
    }
    data = new int[s_capacity - BLOCK_SIZE];
    for(int i=0; i<=s_size-1; i++){
        data[i] = temp[i];
    }
    s_capacity -= BLOCK_SIZE;
    delete temp;
}

