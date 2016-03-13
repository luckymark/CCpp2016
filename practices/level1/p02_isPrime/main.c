#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a,i,sum=0;
    scanf("%d",&a);
    for(i=2;i<=a-1;i++)
    {
        int b=a%i;
        if(b==0)
        {
            sum+=1;
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
    return 0;
}
