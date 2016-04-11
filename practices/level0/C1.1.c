#include<stdio.h>
int main()
{
    int x;
    printf("请输入一个整数\n");
    scanf("%d",&x);
    if(x<0)
        printf("该数为负数");
        else printf("该数为正数");
    if(x%2==0)
        printf("且为偶数\n");
        else printf("且为奇数\n");
        return 0;
}
