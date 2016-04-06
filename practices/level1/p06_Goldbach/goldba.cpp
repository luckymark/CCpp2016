#include <iostream>
#include <cstdio>
#define Maxn 110
#define Up 100
int i,j,use[Maxn];
bool no(int );
void makePrime();
int main()
{
    makeprime();
    for (i=4;i<=Up;i+=2)
    if (no(i))
    {
        printf("%d\n",i);
        printf("NO\n");
        return 0;
    }
    printf("YES\n");
}
void makePrime()
{
    int i,j;
    use[1]=1;
    for (i=2;i<=Up/2;i++)
    if (use[i]==0)
    {
        for (j=i+i;j<=Up;j+=i) use[j]=1;
    }
}
bool no(int a)
{
    int i;
    for (i=2;i<a;i++)
    {
        if (use[i]==0 && use[a-i]==0) return false;
    }
    return true;
}
