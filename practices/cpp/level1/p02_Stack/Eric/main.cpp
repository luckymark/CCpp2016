//cppP02 IntStack
//author : Eric

#include <iostream>
#include "StackTemplate.hpp"

int main()
{
    StackTemplate<int> stack(1000);
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
    std::cout << "The capacity is" << stack.showStackCapacity() << std::endl;
    return 0;
}
