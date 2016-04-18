#ifndef STACK_H
#define STACK_H


class Stack
{
    public:
        Stack();
        Stack(int capbility);
        bool is_empty();
        bool is_full();
        void push(int a);
        int pop();
    protected:
    private:
        int *data;
        int tail=0;
        int head=0;
        int num;
};

#endif // STACK_H
