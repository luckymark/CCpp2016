#include "Stack.h"
#include <stdio.h>
Stack::Stack()
{
    data=NULL;
}

Stack::~Stack()
{
    delete [] data;
}

Stack::Stack(int n){
    data=new int[n];
}

void Stack::push(int item){
    data[head]=item;
    head=head+1;
}

int Stack::pop(){
    head=head-1;
    return data[head];
}

bool Stack::isEmpty(){
    return (head==0);
}

bool Stack::isFull(){
    return (head==100);
}


