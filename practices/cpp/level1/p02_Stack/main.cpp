#include <iostream>
#include "Stack.h"
int main()
{
    int a;
    Stack stack;
    scanf("%d",&a);
    if (!stack.is_full())
    {
        stack.push(a);
    }
    if (!stack.is_empty())
    {

        a=stack.pop();
        printf("%d\n",a);
    }
    return 0;
}

