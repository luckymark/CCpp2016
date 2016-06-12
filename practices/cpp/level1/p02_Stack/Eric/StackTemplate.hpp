#ifndef STACK_TEMPLATE_H
#define STACK_TEMPLATE_H

template<typename T>

class StackTemplate
{
public:
    StackTemplate() = default;
    StackTemplate(int capacity)
    {
        target = new T[capacity];
        fullHead = capacity;
    }
    ~StackTemplate()
    {
        delete target;
    }
    int showStackCapacity();
    bool push(T target);
    T pop();
    bool isFull();
    bool isEmpty();
private:
    T *target;
    int head = -1;
    int fullHead = 100;
    int emptyHead = -1;
};

template<typename T>
int StackTemplate<T>::showStackCapacity()
{
    return fullHead;
}
template<typename T>
bool StackTemplate<T>::push(T target)
{
    if(!isFull())
    {
        this->target[++head] = target;
        return 0;
    }
    else
    {
        std::cout << "ERROR : The stack is full." << std::endl;
    }
}
template<typename T>
T StackTemplate<T>::pop()
{
    if(!isEmpty())
    {
        return this->target[head--];
    }
    else
    {
        std::cout << "ERROR : The stack is empty." << std::endl;
        T temp;
        return temp;
    }
}
template<typename T>
bool StackTemplate<T>::isFull()
{
    return head == fullHead;
}
template<typename T>
bool StackTemplate<T>::isEmpty()
{
    return head == emptyHead;
}
#endif
