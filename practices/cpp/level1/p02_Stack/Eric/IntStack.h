#ifndef INT_STACK_H
#define INT_STACK_H
class IntStack
{
public:
    IntStack() = default;
    IntStack(int stackCapacity)
    {
        num = new int[stackCapacity];
        fullHead = stackCapacity;
    }
    ~IntStack()
    {
        delete num;
    }
    int showStackCapacity();
    bool push(int num);
    int pop();
    bool isFull();
    bool isEmpty();
private:
    int *num;
    int head = -1;
    int fullHead = 100;
    int emptyHead = -1;
};
#endif