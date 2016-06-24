#include "Queue.hpp"

int Queue::next(int ptr) {
    if (ptr >= m_max_size - 1) {
        return 0;
    } else {
        return ptr + 1;
    }
}

void Queue::append(int e) {
    m_tail = next(m_tail);
    m_queue[m_tail] = e;
}

int Queue::pop() {
    int h = m_queue[m_head];
    m_head = next(m_head);
    return h;
}

bool Queue::is_empty() {
    return m_head == m_tail;
}

bool Queue::is_full() {
    return next(m_head) == m_tail;
}
