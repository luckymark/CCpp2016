#ifndef HOMEWORK_QUEUE_H
#define HOMEWORK_QUEUE_H
#define MAX 100

class Queue {
public:
    void push(int item);

    bool isEmpty();

    bool isFull();

    int pop();

private:
    int array[MAX];
    int head = 0, tail = 0;//[head,tail)
};


#endif //HOMEWORK_QUEUE_H
