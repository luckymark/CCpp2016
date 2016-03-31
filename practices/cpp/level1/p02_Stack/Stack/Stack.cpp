#include "Stack.h"
#include <stdio.h>
#define NUMBER 100
int main()
{
    int cability;
    scanf("%d",&cability);
    Stack stack(cability);
    if(!stack.isFull())
    {
        stack.push(NUMBER);
    }
    int n;
    if(!stack.isEmpty())
    {
        n=stack.pop();
    }
    return 0;
}
