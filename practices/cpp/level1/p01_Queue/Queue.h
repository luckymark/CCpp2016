#ifndef HOMEWORK_QUEUE_H
#define HOMEWORK_QUEUE_H
#define MAX 100

class Queue {
public:
    Queue() {
        head = tail = 0;
    }

    void push(int item);

    bool isEmpty();

    bool isFull();

    int pop();

private:
    int array[MAX];
    int head, tail;//[head,tail)
};


#endif //HOMEWORK_QUEUE_H
