#include "Queue.h"
#include <cstdio>
int main() {
    Queue MyQueue;
    //test
    if (MyQueue.isEmpty()) {
        MyQueue.push(10);
    }
    if (!MyQueue.isFull()) {
        printf("%d\n", MyQueue.pop());
    }
    //end test
    return 0;
}
