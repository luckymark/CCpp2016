#include<stdio.h>
int main()
{
    int num,g,s,b;
    for(num=100;num<1000;num++)
    {
        b=num/100;
        s=(num/10)%10;
        g=num%10;
        if(num==b*b*b+s*s*s+g*g*g)
        printf("%d ",num);
    }
    return 0;
}
