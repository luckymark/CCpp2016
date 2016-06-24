#include "InStack.hpp"

template <class data_type>
InStack<data_type>::InStack(int size) {
    m_size = size;
    m_stack = new data_type[size];
}

template <class data_type>
void InStack<data_type>::push(data_type data) {
    m_stack[ptr++] = data;
}

template <class data_type>
data_type InStack<data_type>::pop() {
    return m_stack[--ptr];
}

template <class data_type>
bool InStack<data_type>::full() {
    return ptr == m_size;
}

template <class data_type>
bool InStack<data_type>::empty() {
    return ptr == 0;
}

template <class data_type>
InStack<data_type>::~InStack() {
    delete m_stack;
}
