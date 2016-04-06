#include "Queue.h"

void Queue::append(int v)
{
    data[tail]=v;
    tail=(tail+1)%100;
}
int Queue::pop()
{
    head=(head+1)%100;
    return head;
}
bool Queue::isEmpty()
{
    return head==tail;
}
bool Queue::isFull()
{
    return tail==SIZE-1;
}
