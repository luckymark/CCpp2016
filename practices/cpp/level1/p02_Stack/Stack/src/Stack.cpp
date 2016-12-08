#include "Stack.h"

Stack::Stack(int capbility)
{
    data=new int[capbility];
    top=0;
    this->capbility=capbility;
}
void Stack::push(int v)
{
    data[top]=v;
    top=(top+1)%capbility;
}
int Stack::pop()
{
    top--;
    return top;
}
bool Stack::isFull()
{
    return top==capbility-1;
}
bool Stack::isEmpty()
{
    return top==0;
}
