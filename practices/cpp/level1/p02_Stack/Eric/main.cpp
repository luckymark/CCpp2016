//cppP02 IntStack
//author : Eric

#include <iostream>
#include "IntStack.h"

int main()
{
    IntStack stack;
    if(stack.isEmpty())
    {
        std::cout << "Stack is empty." << std::endl;
    }
    if(!stack.isFull())
    {
        std::cout << "Stack is not Full." << std::endl;
    }
    stack.push(100);
    std::cout << stack.pop() << std::endl;
    
    return 0;
}