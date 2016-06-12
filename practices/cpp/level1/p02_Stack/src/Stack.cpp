#include "Stack.h"

Stack::Stack()
{
    //ctor
}

Stack::Stack(int length)
{
    this->length = length;//ctor
}

void Stack::push(int item){
    if(data.size()<length){
        data.push_back(item);
    }else{
        cout<<"ÒÑÂú"<<endl;
    }
}

int Stack::pop(){
    if(data.size()!=0){
    int value = data.back();
    data.pop_back();
    return value;
    }else{
        cout<<"ÎÞÔªËØ"<<endl;
    }
}
bool Stack::isEmpty(){
    return data.empty();
}

bool Stack::isFull(){
    return data.size()==length;
}
