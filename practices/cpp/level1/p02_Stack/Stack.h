#ifndef STACK_H
#define STACK_H


class Stack
{
    public:
        bool isFull();
        bool isEmpty();
        void push(int item);
        int pop();
        Stack(int n);
        Stack();
        virtual ~Stack();

    protected:

    private:
        int*data;
        int head=0;
};

#endif // STACK_H
;
