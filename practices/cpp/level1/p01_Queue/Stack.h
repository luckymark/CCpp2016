#ifndef HOMEWORK_STACK_H
#define HOMEWORK_STACK_H
class Stack {
public:
    Stack() {
        top = -1;
    }

    void push(int item);

    bool isEmpty();

    bool isFull();

    int pop();

private:
    int array[100];
    int top;
};
#endif
