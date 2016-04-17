#include "Stack.h"
#include <stdio.h>
Stack::Stack()
{
    top=new unit;
    top->last=NULL;
    top->next=NULL;
    top->number=0;
    top->value=0;
}

Stack::~Stack()
{   unit* temp;
    for(int i=top->number;i>=0;i--){
        temp=top;
        top=top->last;
        delete temp;
        temp=NULL;
    }
}

void Stack::push(int item){
    top->next=new unit;
    top->next->last=top;
    top->next->next=NULL;
    top->next->number=(top->number)+1;
    top->next->value=item;
    top=top->next;
}

int Stack::pop(){
    int result=top->value;
    top=top->last;
    delete top->next;
    top->next=NULL;
    return result;
}

bool Stack::isEmpty(){
    return !(top->number);
}


