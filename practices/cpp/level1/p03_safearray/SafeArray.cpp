#include "SafeArray.h"
SafeArray::SafeArray(int maximun):maximun(maximun)
{
    data=new int[maximun];
}
SafeArray::~SafeArray()
{
    delete []data;
}
bool SafeArray::check(int n)
{
    return (n<maximun);
}
void SafeArray::clone(int n,int item)
{
    data[n]=item;
}
