#include<stdio.h>
int main()
{
    int x;
    printf("������һ������\n");
    scanf("%d",&x);
    if(x%13==0)
        printf("����Ϊ13�ı���\n");
    else
        printf("��������13�ı���\n");
    return 0;
}
