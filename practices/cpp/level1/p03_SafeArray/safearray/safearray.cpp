//
//  safearray.cpp
//  safearray
//
//  Created by Ferris on 16/6/1.
//  Copyright © 2016年 Ferris. All rights reserved.
//

#include "safearray.hpp"
#include <iostream>

using namespace std;

SafeArray::SafeArray(int size, bool round){
    if(size <= 0 && !round){
        throw "Creating an empty array";
    }
    size = (size>0)?size:DEFAULT_SIZE;
    data = new int[size];
    a_size = size;
    this->round = round;
}

SafeArray::~SafeArray(){
    delete data;
}

void SafeArray::set(int index, int value){
    index = processIndex(index);
    checkIndex(index);
    data[index] = value;
}

int SafeArray::get(int index){
    index = processIndex(index);
    checkIndex(index);
    return data[index];
}

int& SafeArray::operator[](int index){
    index = processIndex(index);
    checkIndex(index);
    return data[index];
}

ostream & operator<<(ostream & os, SafeArray & a){
    for(int i=0; i<a.a_size; i++){
        os << a.data[i];
        if(i < a.a_size - 1){
            os << '\t';
        }
    }
    return os;
}

int SafeArray::processIndex(int index){
    if(this->round){
        while(index < 0){
            index += a_size;
        }
        return index % a_size;
    } else {
        return index;
    }
}

void SafeArray::checkIndex(int index){
    if(index >= a_size || index < 0){
        throw "Index out of range";
    }
}