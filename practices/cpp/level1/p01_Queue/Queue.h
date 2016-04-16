#ifndef QUEUE_H
#define QUEUE_H
class Queue
{
public:
    bool append(int source);
    int pop();
    bool isFull();
    bool isEmpty();
private:
    int num[100];
    int head = -1;
    const int maxHead = 99;
    const int minHead = -1;
};
#endif