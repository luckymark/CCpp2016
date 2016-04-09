#include <iostream>
#include <cstdio>
#define Maxn 1100
#define Up 500
using namespace std;

int i,use[Maxn],j;
int main()
{
    for (i=2;i<=Up;i++)
    if (use[i]==0)
    {
        for (j=i+i;j<=Up*2;j+=i) 
        {
            use[j]=1;
        }
    }
    for (i=2;i<=Up*2;i++)
    if (use[i]==0)
    {
        printf("%d\n",i);
    }
}
