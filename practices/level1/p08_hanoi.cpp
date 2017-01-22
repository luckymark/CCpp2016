#include <stdio.h>
const int N=64;
void Hanoi(int n1,int a,int b,int c);
int main()
{
    Hanoi(N,'a','b','c');
    return 0;
}
void Hanoi(int n1,int a,int b,int c)
{
    if  (1==n1)
    {
        printf("%c->%c\n",a,c);
    }
    else
    {
        Hanoi(n1-1,a,c,b);
        printf("%c->%c\n",a,c);
        Hanoi(n1-1,b,a,c);
    }
}
