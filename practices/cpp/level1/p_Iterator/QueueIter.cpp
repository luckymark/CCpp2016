#include "QueueIter.hpp"

QueueIter::QueueIter(int index, Queue *queue): m_index(index), m_queue(queue) {}

QueueIter QueueIter::operator++() {
    m_index = m_queue->next(m_index);
    return *this;
}

QueueIter QueueIter::operator++(int) {
    auto tem = *this;
    m_index = m_queue->next(m_index);
    return tem;
}

bool QueueIter::operator==(QueueIter &qi) {
    return m_index == qi.m_index;
}
bool QueueIter::operator!=(QueueIter &qi) {
    return m_index != qi.m_index;
}
int QueueIter::operator*() {
    return m_queue->m_queue[m_index];
}
