#ifndef INT_STACK_H
#define INT_STACK_H
class IntStack
{
    public:
    IntStack() = default;
    //IntStack(int stackCapacity) : num(new int[stackCapacity]), fullHead(stackCapacity) {};
    IntStack(int stackCapacity)
    {
        num = new int[stackCapacity];
        fullHead = stackCapacity;
    } 
    //echo the stackCapacity
    int showStackCapacity();
    //入栈
    bool push(int num);
    //出栈
    int pop();
    //is stack full
    bool isFull();
    //is stack empty
    bool isEmpty();
    private:
    int *num;
    int head = -1;
    int fullHead = 100;
    int emptyHead = -1;
};
#endif