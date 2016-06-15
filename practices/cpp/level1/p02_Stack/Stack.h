#ifndef STACK_H
#define STACK_H
class Stack
{
 public:
    void push(int item);
    int pop();
    bool is_empty();
    bool is_full();

 private:
    int data[100];
    int head=0;
};
#endif
