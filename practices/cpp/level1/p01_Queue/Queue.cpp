#include "Queue.h"
#include <iostream>

bool Queue::append(int source)
{
    if(!isFull())
    {
        num[++head] = source;
        return 0;
    }
    else
    {
        std::cout << "ERROR : Queue is FULL." << std::endl;
        return 1;
    }
}
int Queue::pop()
{
    if(!isEmpty())
    {
        return num[head--];
    }
    else
    {
        std::cout << "ERROR : Queue is EMPTY." << std::endl;
        return -1;
    }
}
bool Queue::isFull()
{
    return head == maxHead;
}
bool Queue::isEmpty()
{
    return head == minHead;
}