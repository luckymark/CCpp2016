#ifndef INT_STACK_H
#define INT_STACK_H
class IntStack
{
    public:
    //入栈
    bool push(int num);
    //出栈
    int pop();
    //is stack full
    bool isFull();
    //is stack empty
    bool isEmpty();
    private:
    int num[100];
    int head = -1;
    const int fullHead = 100;
    const int emptyHead = -1;
};
#endif