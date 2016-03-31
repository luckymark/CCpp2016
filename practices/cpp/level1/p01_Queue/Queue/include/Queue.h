#ifndef QUEUE_H
#define QUEUE_H
#define SIZE 100

class Queue
{
    public:
        void append(int v);
        int pop();
        bool isEmpty();
        bool isFull();
    private:
        int data[SIZE];
        int head=0;
        int tail=0;
};

#endif // QUEUE_H
