#include<stdio.h>
int main()
{
    int n;
    printf("请输入年份\n");
    scanf("%d",&n);
    if((n%4==0&&n%100!=0)||(n%400==0))
        printf("该年份为闰年\n");
    else printf("该年份不为闰年\n");
    return 0;
}
