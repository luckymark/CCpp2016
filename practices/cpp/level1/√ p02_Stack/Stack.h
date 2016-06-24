//
// Created by Administrator on 2016/3/28.
//

#ifndef PRACTICE_STACK_H
#define PRACTICE_STACK_H


class Stack {
public:
    Stack(int capbility);
    void push(int item);
    int pop();
    bool isEmpty();
    bool isFull();

private:
    int *data;
    int top = 0;;
};


#endif //PRACTICE_STACK_H
