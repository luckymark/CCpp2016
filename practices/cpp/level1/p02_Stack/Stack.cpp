#include "Stack.h"
#include <iostream>
#include <cstdio>
int Stack::pop()
{
	head--;
    return data[head+1];
}
void Stack::push(int item)
{
    head++;
    data[head]=item;
}
bool Stack::is_full()
{
    return (head==100);
}
bool Stack::is_empty()
{
    return head==0;
}


