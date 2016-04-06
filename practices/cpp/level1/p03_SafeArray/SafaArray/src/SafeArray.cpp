#include "SafeArray.h"
#include <cstdio>
int SafeArray::get(int pos)
{
    if(pos<capbility)
    {
        return data[pos];
    }
    else
    {
        printf("The size is too large!\n");
        return -1;
    }
}
void SafeArray::insert(int pos,int value)
{
    if(pos<capbility)
    {
        data[pos]=value;
    }
    else
    {
        printf("The size is too large!\n");
    }
}
