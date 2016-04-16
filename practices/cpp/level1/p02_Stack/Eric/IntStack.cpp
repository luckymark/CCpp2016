#include "IntStack.h"
#include <iostream>
int IntStack::showStackCapacity()
{
    return fullHead;
}
bool IntStack::push(int num)
{
    if(!isFull())
    {
        this->num[++head] = num;
        return 0;
    }
    else
    {
        std::cout << "ERROR : The stack is full." << std::endl;
    }
}
int IntStack::pop()
{
    if(!isEmpty())
    {
        return this->num[head--];
    }
    else
    {
        std::cout << "ERROR : The stack is empty." << std::endl;
        return -1;
    }
}
bool IntStack::isFull()
{
    return head == fullHead;
}
bool IntStack::isEmpty()
{
    return head == emptyHead;
}