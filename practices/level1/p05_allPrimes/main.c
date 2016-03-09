#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,j;
    for(i=2;i<=1000;i++)
    {
        int sum=0;
        for(j=2;j<=i-1;j++)
        {
            int k=i%j;
            if(k==0)
            {
                sum++;
            }
        }
        if(sum==0)
        {
            printf("%d\n",i);
        }
    }
    return 0;
}
