#ifndef INTSTACK_H
#define INTSTACK_H
class IntStack{
public:
    IntStack(int n,int point);
    ~IntStack();
    void push(int item);
    int pop();
    bool isEmpty();
    bool isFull(int n);
private:
    int *data;
    int point;
};
#endif // INTSTACK_H
