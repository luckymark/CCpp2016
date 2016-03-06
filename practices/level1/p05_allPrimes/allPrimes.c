#include<stdio.h>
#include<time.h>
int main()
{
    int a[101];
    memset(a,1,101*sizeof(int));
    clock_t t1=clock();
    printf("2\n");
    for(int i=3;i<34;i+=2)
    {
        for(int j=3;i*j<101;j+=2)
        {
            a[i*j]=0;
        }
    }
    for(int i=3;i<101;i+=2)
    {
        if(a[i]!=0)
        {
            printf("%d\n",i);
        }
    }
    clock_t t2=clock();
    printf("time:%d\n",t2-t1);
    return 0;
}

