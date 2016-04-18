#include<stdio.h>
#include<time.h>
#define RANGE 101
int main()
{
    int a[RANGE];
    memset(a,1,RANGE*sizeof(int));
    clock_t t1=clock();
    printf("2\n");//2是唯一是偶数的素数
    for(int i=3;i<RANGE;i+=2)
    {
        for(int j=3;i*j<RANGE;j+=2)
        {
            a[i*j]=0;//筛选
        }
    }
    for(int i=3;i<RANGE;i+=2)//直接排除偶数
    {
        if(a[i])
        {
            printf("%d\n",i);
        }
    }
    clock_t t2=clock();
    printf("time:%d\n",t2-t1);
    return 0;
}
