//
// Created by kp600168 on 2016/6/12.
//

#ifndef STACK_STACK_H
#define STACK_STACK_H
#include<assert.h>
template<class T,int capability>
class Stack {
private:
    T array[capability];
    int head = 0;
public:
    void push(T something) {
        array[head++] = something;
    }

    T pop() {
        assert(head);
        return array[--head];
    }

    bool isEmpty() {
        return (head == 0);
    }

    bool isFull() {
        return (head == capability);
    }
};


#endif //STACK_STACK_H
