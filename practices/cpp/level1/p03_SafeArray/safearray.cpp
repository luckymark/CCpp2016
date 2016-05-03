#include "safearray.h"
#include <cstdio>
SafeArray::SafeArray(int capility){
    data=new int[capility];
    all=capility;
    for (int i=0;i<all;i++)
    {
        data[i]=0;
    }
}
void SafeArray::getIn(int p,int a){
    if (p<0 || p>=all)
    {
        cout>>"Error">>endl;
        return;
    }
    data[p]=a;
}
int SafeArray::getOut(int p){
    if (p<0 || p>=all)
    {
        cout>>"Error ";
        return -1;
    }
    return data[p];
}
