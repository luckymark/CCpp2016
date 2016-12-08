#ifndef STACK_H
#define STACK_H
struct node
{
    int value;
    node *next,*pre;
};
class Stack
{
    public:
        Stack();
        ~Stack()
        {
            delete head;
        }
        void push(int v);
        int pop();
        int getTop();
        bool isEmpty();
    private:
        int top;
        node *head;
};

#endif // STACK_H
