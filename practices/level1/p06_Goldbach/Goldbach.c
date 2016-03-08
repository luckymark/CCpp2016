#include<stdio.h>
#include"prime.h"
#define RANGE 101
int judge;
int add_judge(int b)
{
    for(int k=2,l;k<RANGE;k++)
        {
            for(int l=2;l<RANGE;l++)
            {
                if(is_prime(k)&&is_prime(l))
                {
                     if(k+l==b)
                     {
                         if(judge)
                         {
                             printf("%d=%d+%d\n",b,k,l);
                         }
                         return 1;
                     }
                }
            }
        }
    return 0;//如果不存在，就返回0
}
int main()
{
    int flag=0;
    printf("是否需要看证明步骤？\n请输入1代表要看，输入0代表不看\n");
    scanf("%d",&judge);
    for(int i=4;i<RANGE;i+=2)
    {
        if(!add_judge(i))
        {
            printf("哥德巴赫猜想在100以内不成立\n");
            flag+=1;
            break;
        }
    }
    if(!flag)
    {
        printf("哥德巴赫猜想在100以内成立\n");
    }
    return 0;
}

