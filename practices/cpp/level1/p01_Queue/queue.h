//
// Created by Administrator on 2016/4/18.
//

#ifndef P01_QUEUE_QUEUE_H
#define P01_QUEUE_QUEUE_H


class Queue{

public:
    void append(int item) ;
    int pop() ;
    bool isEmpty();
    bool isFull() ;
private:
    int data[100];
    int head = 0;
    int tail = 0;
};


#endif //P01_QUEUE_QUEUE_H
