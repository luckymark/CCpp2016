#include<stdio.h>
void move(char, char);
void han(int, char, char, char);
int main()
{
    int n;
    scanf("%d",&n);
    printf("%d\n",(1<<n)-1);
    han(n,'A','B','C');
    return 0;
}
void move(char a,char b)
{
    printf("%c->%c\n",a,b);
    return;
}
void han(int n,char a,char b,char c)
{
    if(n>0)
    {
        han(n-1,a,c,b);
        move(a,b);
        han(n-1,c,b,a);
    }
    return;
}