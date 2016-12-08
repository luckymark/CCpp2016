#include "Stack.h"
#include <stdio.h>
#define NUMBER 100
int main()
{
    Stack stack;
    stack.push(NUMBER);
    int n;
    if(!stack.isEmpty())
    {
        n=stack.pop();
    }
    return 0;
}
