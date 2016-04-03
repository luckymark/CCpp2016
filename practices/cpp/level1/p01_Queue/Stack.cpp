#include "Stack.h"
#define EMPTY -1
#define FULL 99
void Stack::push(int item) {
    array[++top] = item;
}

bool Stack::isEmpty() {
    return top == EMPTY;
}

bool Stack::isFull() {
    return top == FULL;
}

int Stack::pop() {
    return array[top--];
}
