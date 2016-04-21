#include "IntStack.h"
IntStack::IntStack(int n,int point):point(point)
{
    data=new int[n];
}
IntStack::~IntStack()
{
    delete []data;
}
void IntStack::push(int item)
{
    data[point]=item;
    point++;
}
int IntStack::pop()
{
    point--;
    return data[point+1];
}
bool IntStack::isFull(int n)
{
    return (point+1==n);
}
bool IntStack::isEmpty()
{
    return (point==0);
}
