#ifndef stack_h
#define stack_h
class Stack
{
public:
    void push(int);
    int pop();
    bool isEmpty();
    bool isFull();
private:
    int num[100];
    int p=0;
};
#endif
