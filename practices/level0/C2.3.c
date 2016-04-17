#include<stdio.h>

int main()
{
    int sum=0,i;
    for(i=0;i<101;i++)
    {
        if(i!=0 && i%7==0 || i%10==7)
        {
            printf("%d\n",i);
            sum=sum+i;
        }
    }
    printf("%d\n",sum);
}
