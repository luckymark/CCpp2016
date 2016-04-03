#include "Queue.h"
#define EMPTY -1
#define FULL 99
void Queue::push(int item) {
    array[tail++] = item;
    tail %= MAX;
}

bool Queue::isEmpty() {
    return head == tail;
}

bool Queue::isFull() {
    return head == (tail + 1) % MAX;
}

int Queue::pop() {
    int ans = array[head++];
    head %= MAX;
    return ans;
}
