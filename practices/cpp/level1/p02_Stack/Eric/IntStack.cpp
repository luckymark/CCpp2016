#include "IntStack.h"
#include <iostream>

bool IntStack::push(int num)
{
    if(!isFull())
    {
        IntStack::num[++head] = num;
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
        return IntStack::num[head--];
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