#ifndef QUEUE_ITER_HPP
#define QUEUE_ITER_HPP
#include "Queue.hpp"

class QueueIter {
private:
    int m_index;
    Queue *m_queue;
public:
    QueueIter(int index, Queue *queue);
    QueueIter operator++();
    QueueIter operator++(int);
    bool operator==(QueueIter &qi);
    bool operator!=(QueueIter &qi);
    int operator*();
};
#endif
