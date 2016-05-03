#include <stdio.h>
#include <stdlib.h>

int IsPrime();
int main()
{
    int i,j;
    for(i=4;i<=100;i+=2)
        for(j=2;j<=i/2;j++)
        {
            if(IsPrime(j)==1)
            {
                if(IsPrime(i-j)==1)
                {
                    printf("%d=%d+%d\n",i,j,i-j);
                    break;
                }
            }
        }
    return 0;
}
int IsPrime(int a)
{
    int i,sum=0;
    for(i=2;i<=a-1;i++)
    {
        int b=a%i;
        if(b==0)
        {
            sum++;
        }
    }
    return sum==0?1:0;
}
