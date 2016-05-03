#include "SafeArray.h"
#include <iostream>
using namespace std;
SafeArray::SafeArray(int capbility) {
    this->capbility=capbility;
    data=new int[capbility];
}
SafeArray::~SafeArray() {
    delete data;
}
int SafeArray::get(int pos) {
    if(pos<capbility) {
        return data[pos];
    }else{
        cout<<"err,size is overflow"<<endl;
        return 0;
    }
}
void SafeArray::insert(int pos,int value) {
    if(pos<capbility) {
        data[pos]=value;
    }else{
        cout<<"err,size is overflow"<<endl;
    }
}
