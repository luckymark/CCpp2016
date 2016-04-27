#include <iostream>
#include <cstdio>
#include "safearray.h"
int main(){
    int p,a;
    SafeArray data(100);

    scanf("%d%d",&p,&a);
    data.getIn(p,a);

    scanf("%d",&p);
    printf("%d\n",data.getOut(p));
}
