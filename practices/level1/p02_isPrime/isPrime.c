#include<stdio.h>
#include"prime.h"
int main()
{
    int a;
    scanf("%d",&a);
    if(is_prime(a))
    {
        printf("Yes\n");
    }
    else
    {
        printf("No\n");
    }
    return 0;
}
