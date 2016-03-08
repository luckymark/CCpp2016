#include<stdio.h>
#include<time.h>
#define MAX 1001
int main()
{   clock_t t1,t2;
    t1=clock();
    int num[MAX]={1,1};
    for(int i=2;i<MAX;i++)
    {
        if(!num[i])
       {
            printf("%d  ",i);
            for(int j=i+i;j<=MAX-1;j+=i)
            {
                num[j]=1;
            }
        }
    }

    t2=clock();
    printf("%g seconds",(t2-t1)/(double)CLOCKS_PER_SEC);
    return 0;
}
