#include<stdio.h>
int main()
{
    int a,b,c,max;
    printf("������������\n");
    scanf("%d %d %d",&a,&b,&c);
    if(a>b)
        max=a;
    else
        max=b;
    if(max>c)
        printf("������Ϊ%d\n",max);
    else
        printf("������Ϊ%d\n",c);
    return 0;
}
