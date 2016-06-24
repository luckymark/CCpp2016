#ifndef QUEUE_HPP__
#define QUEUE_HPP__

#define MAX_SIZE 100

class Queue {
private:
    int m_max_size = MAX_SIZE;
    int m_queue[MAX_SIZE];
    int m_head = 0;
    int m_tail = 0;
    int next(int ptr);
public:
    void append(int e);
    int pop();
    bool is_empty();
    bool is_full();
    Queue();
};

#endif
