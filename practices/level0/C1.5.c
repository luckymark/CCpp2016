#include<stdio.h>
int main()
{
    int a,b,c,max;
    printf("输入三个整数\n");
    scanf("%d %d %d",&a,&b,&c);
    if(a>b)
        max=a;
    else
        max=b;
    if(max>c)
        printf("最大的数为%d\n",max);
    else
        printf("最大的数为%d\n",c);
    return 0;
}
