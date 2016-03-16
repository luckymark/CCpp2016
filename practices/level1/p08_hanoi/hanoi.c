#include<stdio.h>
void hanoi(int n,char a,char b,char c);
int main()
{
    int n;
    scanf("%d",&n);
    hanoi(n,'a','b','c');
    return 0;
}
void hanoi(int n,char a,char b,char c)
{
    if(1==n)
    {
        printf("\n%c--<%c",a,c);
    }
    else
    {
        hanoi(n-1,a,c,b);
        printf("\n%c--<%c",a,c);
        hanoi(n-1,b,a,c);

    }
}
