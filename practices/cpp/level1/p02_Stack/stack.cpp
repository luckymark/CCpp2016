#include "stack.h"
int Stack::pop()
{
    return num[p--];
}
bool Stack::isEmpty()
{
    return p==0;
}
bool Stack::isFull()
{
    return p==99;
}
void Stack::push(int item)
{
    num[++p]=item;
}
