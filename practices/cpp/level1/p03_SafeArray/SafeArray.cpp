#include "SafeArray.h"
#include <iostream>

SafeArray::SafeArray()
{
    data=NULL;
    maxsize=0;
}

SafeArray::SafeArray(int n){
    data=new int[n];
    maxsize=n;
}

SafeArray::~SafeArray()
{
    delete []data;
}

bool SafeArray::result(int n){
    if(n<0||n>=maxsize){
       std::cout<<"ERROR!";
        return false;
    }else{
        return true;
    }
}

void SafeArray::write(int n,int x){
    int what=1;
    what=result(n);
    if(what==1){
       data[n]=x;
    }else{}
}

int SafeArray::read(int n){
    int what=1;
    what=result(n);
    if(what==1){
       return data[n];
    }else{
       return -1;
    }
}
