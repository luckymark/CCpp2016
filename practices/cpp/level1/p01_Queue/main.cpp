//
// Created by Administrator on 2016/4/18.
//
#include "queue.h"

int main() {
    Queue queue;
    if (!queue.isFull()) {
        queue.append(100);
    }

    int n;
    if (!queue.isEmpty()) {
        n = queue.pop();
    }
}