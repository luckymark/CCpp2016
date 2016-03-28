#include <stdio.h>
#include <stdlib.h>

void primeOrNot(int a)
{
    int i,sum=0;
    for(i=2;i<=a-1;i++)
    {
        int b=a%i;
        if(b==0)
        {
            sum++;
            if(sum>=1) break;
        }
    }
    if(sum==0)
    {
        printf("a prime,obviously\n");
    }
    else
    {
        printf("not a prime indeed\n");
    }
}
int main()
{
    int a;
    scanf("%d",&a);
    primeOrNot(a);
    return 0;
}
