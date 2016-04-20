#include <stdio.h>
#include <stdlib.h>

void isPrime(int a);
int main()
{
    int a;
    scanf("%d",&a);
    isPrime(a);
    return 0;
}
void isPrime(int a)
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
    if(sum==0)
    {
        printf("a prime,obviously\n");
    }
    else
    {
        printf("not a prime indeed\n");
    }
}
