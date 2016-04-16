//p01_Queue
//author : Eric

#include <iostream>
#include "Queue.h"

int main()
{
    Queue queue;
    if(!queue.isFull())
    {
        std::cout << "Queue is not Full." << std::endl;
    }
    if(queue.isEmpty())
    {
        std::cout << "Queue is Empty." << std::endl;
    }
    queue.append(100);
    std::cout << "POP : " << queue.pop() << std::endl;
    std::cout << "POP security-check : " << queue.pop() << std::endl;
    return 0;
}