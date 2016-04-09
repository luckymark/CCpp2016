#include <iostream>
#include <cstdio>

void search(char ,char ,char ,int );

int main()
{
    int n;
    scanf("%d",&n);
    search('A','B','C',n);
}

void search(char a,char b,char c,int p)
{
    if (p==1)
    {
        printf("%c->%c\n",a,c);
        return;
    }
    search(a,c,b,p-1);
    printf("%c->%c\n",a,c);
    search(b,a,c,p-1);
}
