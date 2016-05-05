#include "SafeArray.h"
#include <cstdio>
SafeArray::SafeArray(int capbility)
{
    data=new int[capbility];
    this->capbility=capbility;
}

SafeArray::~SafeArray()
{
    delete [] data;
}
void SafeArray::pop(int b,int c)
{
    if(!SafeArray::is_safe(b))
    {
        printf("error 0\n");
        return;
    }
    data[b]=c;
}
bool SafeArray::is_safe(int a)
{
    return (a<capbility);
}
int SafeArray::load(int a)
{
    if(!SafeArray::is_safe(a))
    {
        printf("error ");//越界时报error 0
        return 0;
    }
    return data[a];
}
