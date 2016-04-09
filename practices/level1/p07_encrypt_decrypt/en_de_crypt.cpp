#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

#define Mo 131
#define Maxn 200000

int num[Maxn],i,l;
char s[Maxn];

void getRand();
void read();
void en_de_crypt(int );

int main()
{
    getRand();
    read();
}
void getRand()
{
    for (int i=0;i<Maxn;i++)
    {
        num[i]=rand()%Mo;
    }
}
void read()
{
    int p;
    scanf("%d\n",&p);
    gets(s);
    l=strlen(s);
    if (p==1)
    {
        en_de_crypt(1);
    }
    if (p==2)
    {
        en_de_crypt(-1);
    }
    printf("%s\n",s);
}
void en_de_crypt(int a)
{
    int i;
    for (i=0;i<l;i++)
    {
        s[i]=(s[i]+Mo+a*num[i])%Mo;
    }
}
