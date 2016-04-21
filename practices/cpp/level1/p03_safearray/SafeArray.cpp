#include "SafeArray.h"
SafeArray::SafeArray(int max):max(max)
{
    data=new int[max];
}
SafeArray::~SafeArray()
{
    delete []data;
}
bool SafeArray::check(int n)
{
    return (n<max);
}
void SafeArray::clone(int n,int item)
{
    data[n]=item;
}
