#include <iostream>
#include <cstdio>
#include <cstring>
#include "stack.h"
using namespace std;
int main()
{
    int a;
    Stack stack;
    scanf("%d",&a);
    if (!stack.isFull())
    {
        stack.push(a);
    }
    if (!stack.isEmpty())
    {
        a = stack.pop();
        printf("%d\n",a);
    }
    return 0;
}
