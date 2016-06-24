//
// Created by wxdao on 16-6-15.
//

#include "Queue.h"

bool Queue::isEmpty() {
    return index == 0;
}

bool Queue::isFull() {
    return index == 100;
}

void Queue::append(int data) {
    if (!isFull()) {
        queue[index++] = data;
    }
}

int Queue::pop() {
    int res = -1;
    if (!isEmpty()) {
        res = queue[0];
        for (int i = 0; i < index - 1; ++i) {
            queue[i] = queue[i + 1];
        }
        --index;
    }
    return res;
}

