#include "Queue.h"

void Queue::append(int item)
{
    data[head]=item;
    head=(head+1)%MAX;
}

int Queue::pop()
{
    tail=(tail+1)%MAX;
    return data[(tail+MAX-1)%MAX];
}

bool Queue::isEmpty()
{
    return (head==tail);
}

bool Queue::isFull()
{
    return ((head+1)%MAX==tail);
}
