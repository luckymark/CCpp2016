#include<stdio.h>
int main()
{
    int i,num,temp;
    for (i=100;i<=999;i++)
    {
        int sum=0;
        temp=i;
        while (temp)
        {
            num=temp%10;
            sum+=num*num*num;
            temp/=10;
        }
        if (sum==i)
        {
            printf("%d\n",i);
        }
    }
    return 0;
}
