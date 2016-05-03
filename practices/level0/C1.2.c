#include<stdio.h>
int main()
{
    int x;
    printf("请输入一个整数\n");
    scanf("%d",&x);
    if(x%13==0)
        printf("该数为13的倍数\n");
    else
        printf("该数不是13的倍数\n");
    return 0;
}
