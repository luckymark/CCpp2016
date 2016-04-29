#ifndef STACK_H
#define STACK_H
class Stack 
{
public:
    Stack(int capbility);
    Stack();/*Îö¹¹º¯Êý*/ 
    void push(int item);
    int pop();
    bool isFull(int capbility);
    bool isEmpty();
private:
    int first = 0;
    int last;
    int *data;
};
#endif
