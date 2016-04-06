#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;
bool can(int );

int main()
{
    int n;
    scanf("%d",&n);
    if (can(n)) printf("YES\n"); else printf("NO\n");
}

bool can(int a)
{
    int i,r=int(sqrt(a));
    if (a==1) return false;
    for (i=2;i<=r;i++)
    {
        if (a%i==0) return false;
    }
    return true;
}
