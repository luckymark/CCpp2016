//
// Created by wxdao on 16-6-15.
//

#ifndef BORING_QUEUE_H
#define BORING_QUEUE_H


class Queue {
private:
    int queue[100];
    int index = 0;
public:
    bool isEmpty();

    bool isFull();

    void append(int);

    int pop();
};


#endif //BORING_QUEUE_H
