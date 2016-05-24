#include "Queue.h"
#include <iostream>
#include <cstdio>
int Queue::pop()
{
    int n=data[head];
    head=(head+1)%100;
    return n;
}
void Queue::append(int item)
{
    data[tail]=item;
    tail=(tail+1)%100;
}
bool Queue::is_full()
{
    return ((tail+1)%100==head);
}
bool Queue::is_empty()
{
    return head==tail;
}


