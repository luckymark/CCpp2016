#include <iostream>
#include <cstdio>
using namespace std;
bool can(int );

int main()
{
    for (int i=1;i<=1000;i++)
    if (can(i))
    {
        printf("%d\n",i);
        return 0;
    }
}

bool can(int a)
{
    int b;
    if (a%6 || a%12 || a%7) return false;
    b=a-a/6-a/12-a/7-9;
    if (b<=0) return false;
    if (a%b==0 && a/b==2) return true;
    return false;
}
