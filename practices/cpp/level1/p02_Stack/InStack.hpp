#ifndef IN_STACK_HPP__
#define IN_STACK_HPP__

template <class data_type>
class InStack {
private:
    int ptr = 0;
    int m_size;
    data_type *m_stack;
public:
    InStack(int size);
    void push(data_type data);
    data_type pop();
    bool full();
    bool empty();

    virtual ~InStack ();
};

#endif
