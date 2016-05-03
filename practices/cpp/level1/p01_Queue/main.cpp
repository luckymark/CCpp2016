#include"Queue.h"
#include<iostream>

int main() {
    Queue queue;
    int n = 10;
    if (!queue.is_full())
    {
        queue.append(n);
    }
    if (!queue.is_empty())
    {
        std::cout<<queue.pop();
    }
    return 0;
}
