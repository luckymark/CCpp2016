#include <stdio.h>
#include <stdlib.h>

void IsPrime(int a);
int main()
{
    int i;
    for(i=2;i<=1000;i++)
        IsPrime(i);
    return 0;
}
void IsPrime(int a)
{
    int i,sum=0;
    for(i=2;i<=a-1;i++)
    {
        int k=a%i;
        if(k==0)
        {
            sum++;
        }
    }
    if(sum==0)
    {
        printf("%d\n",a);
    }
}

