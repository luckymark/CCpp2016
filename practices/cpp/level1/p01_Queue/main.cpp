#include <iostream>
#include <cstdio>
#include "queque.h"
int main()
{
    int a;
    Queue queue;
    scanf("%d",&a);
    if (!queue.is_full())
    {
        queue.append(a);
    }
    if (!queue.is_empty())
    {

        a = queue.pop();
        printf("%d\n",a);
    }
    return 0;
}
