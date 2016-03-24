#include<stdio.h>
int move(int n);
int main()
{
    int n;
    scanf("%d",&n);
    printf("%d",move(n));
    return 0;
}
int move(int n)
{
    if (n == 1) return 1;
    return (1 + move(n - 1) * 2);
}
