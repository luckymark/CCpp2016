#include "Stack.h"
#include <stdio.h>
#define NUMBER 100
int main()
{
    Stack stack;
    for(int i=1;i<=100;i++)
    {
        stack.push(NUMBER);
    }
    int n;
    if(!stack.isEmpty())
    {
        n=stack.pop();
    }
    if(!stack.isEmpty())
    {
        printf("top=%d\n",stack.getTop());
    }
    return 0;
}
