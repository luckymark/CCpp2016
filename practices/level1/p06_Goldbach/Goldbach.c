#include<stdio.h>
int add_judge(int b)
{
    int a[25]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};
    for(int k=0,l;k<26;k++)
        {
            for(int l=0;l<26;l++)
            {
                if(a[k]+a[l]==b)
                {
                    printf("%d=%d+%d\n",b,a[k],a[l]);
                    return 1;
                }
            }
        }
    return 0;//如果不存在，就返回0
}
int main()
{
    for(int i=4;i<101;i+=2)
    {
        if(add_judge(i)==0)
        {
            printf("不成立\n");
            break;
        }
    }
    return 0;
}
