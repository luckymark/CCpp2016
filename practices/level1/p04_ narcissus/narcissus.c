#include<stdio.h>
int main()
{
    for(int num=100;num<1000;num++)
    {
        int b=num/100;
        int s=(num/10)%10;
        int g=num%10;
        if(num==b*b*b+s*s*s+g*g*g)
        {
            printf("%d ",num);
        }
    }
    return 0;
}
