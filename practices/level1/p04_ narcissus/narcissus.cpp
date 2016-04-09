#include <iostream>
#include <cstdio>
using namespace std;

bool can(int );
int  cube(int );

int main()
{
    for (int i=100;i<=999;i++)
    {
        if (can(i))
        {
            printf("%d\n",i);
        }
    }
}
int cube(int a)
{
    return a*a*a;
}
bool can(int a)
{
    int y=a,all=0;
    for (int i=1;i<=3;i++)
    {
        all+=cube(a%10);
        a=a/10;
    }
    if (all==y)
    {
        return true;
    }
    return false;
}
