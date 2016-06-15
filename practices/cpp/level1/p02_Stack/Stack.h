//
// Created by wxdao on 16-6-15.
//

#ifndef BORING_STACK_H
#define BORING_STACK_H

#include <exception>
#include <stdexcept>

template<class T>
class Stack {
private:
    T stack[100];
    int index;
public:
    bool isEmpty() {
        return index == 0;
    }

    bool isFull() {
        return index == 100;
    }

    void append(T data) {
        if (!isFull()) {
            stack[index++] = data;
        }
    }

    T pop() {
        if (!isEmpty()) {
            return stack[--index];
        }
        throw std::out_of_range("stack is empty");
    }
};


#endif //BORING_STACK_H
