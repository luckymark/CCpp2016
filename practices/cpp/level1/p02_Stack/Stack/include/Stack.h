#ifndef STACK_H
#define STACK_H


class Stack
{
    public:
        Stack(int capbility);
        void push(int v);
        int pop();
        bool isFull();
        bool isEmpty();
    private:
        int capbility;
        int top;
        int *data;
};

#endif // STACK_H
