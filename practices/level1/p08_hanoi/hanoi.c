#include<stdio.h>
#define N 64
void hanoi(int n,char from,char by,char to);
int main()
{
    hanoi(N,'A','B','C');
    return 0;
}
void hanoi(int n,char from,char by,char to)
{
    if(n==1)
    {
        printf("%c->%c\n",from,to);
        return;
    }
    hanoi(n-1,from,to,by);
    printf("%c->%c\n",from,to);
    hanoi(n-1,by,from,to);
}
