#include<iostream>
#include "queque.h"

int main()
{
    int a = 5;
    int *pa;
    pa = &a;
    std::cout<<pa;
    Queue queue;
    int n  = 10;
    if (!queue.is_full())
    {
        queue.append(n);
    }
    if (!queue.is_empty())
    {
        
        n = queue.pop();
        std::cout<<n;
    }
    return 0;
}