#include "safe_array.h"
#include <cstdio>
safe_array::safe_array(int capbility)
{
    data=new int[capbility];
    len=capbility;
}

safe_array::~safe_array()
{
    delete [] data;
}
void safe_array::pop(int b,int c)
{
    if(!safe_array::is_safe(b))
    {
        printf("error 0\n");
        return;
    }
    data[b]=c;
}
bool safe_array::is_safe(int a)
{
    return (a<len);
}
int safe_array::load(int a)
{
    if(!safe_array::is_safe(a))
    {
        printf("error ");//越界时报error 0
        return 0;
    }
    return data[a];
}
