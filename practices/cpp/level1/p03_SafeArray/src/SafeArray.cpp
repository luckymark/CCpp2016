#include "SafeArray.h"

SafeArray::SafeArray()
{
    //ctor
}

SafeArray::SafeArray(int length)
{
    this->length = length;
    data = new int[length];//ctor
}
SafeArray::~SafeArray()
{
    //dtor
}

int SafeArray::getItem(int num)
{
    if(num<=length-1&&num>=0){
        return data[num];
    }else{
        cout<<"越界了"<<endl;
    }
}

void SafeArray::setItem(int num,int value)
{
    if(num<=length-1&&num>=0){
        data[num] = value;
    }else{
        cout<<"越界了"<<endl;
    }
}
