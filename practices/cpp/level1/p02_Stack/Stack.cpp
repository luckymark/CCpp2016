//
// Created by Administrator on 2016/3/28.
//

#include "Stack.h"

void Stack::push(int item) {
    data[top] = item;
    top++;
}

int Stack::pop() {
    top--;
    return data[top];
}

bool Stack::isEmpty() {
    return (!top);
}

bool Stack::isFull() {
    return(top==99);
}