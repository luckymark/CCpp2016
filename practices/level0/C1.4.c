#include<stdio.h>
int main()
{
    int a,b;
    printf("请输入两个整数\n");
    scanf("%d %d",&a,&b);
    if(a>b)
        printf("最大的数为%d\n",a);
    else
        printf("最大的数为%d\n",b);
    return 0;

}
