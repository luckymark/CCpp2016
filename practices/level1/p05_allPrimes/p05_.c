#include<stdio.h>
#include<math.h>
#include<time.h>
int a[1000]={0};
int main()
{
    clock_t start_clock=clock();
    long i,j;
    for(i=2;i<=trunc(sqrt(1000));i++)
    {
        if(0==a[i])
        {
            for(j=2;j<=(1000/i);j++)
            {
                a[i*j]=1;
            }
        }
    }
    for(i=2;i<=1000;i++)
    {
        if(0==a[i])
        {
            printf("%d\n",i);
        }
    }
    printf("%g",(clock()-start_clock)/(double)CLOCKS_PER_SEC);
    return 0;
}
