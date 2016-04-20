#ifndef QUEUE_H
#define QUEUE_H
class Queue{
public:
    void append(int item);
    int pop();
    bool isEmpty();
    bool isFull();
private:
    int data[100];
    int head=0;
    int tail=0;
};
#endif // QUEUE_H
