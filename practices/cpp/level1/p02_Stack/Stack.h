class Stack {
public:
    Stack(int capbility);
    bool is_full();
    bool is_empty();
    int pop();
    void append(int n);
    ~Stack()
    {
        delete [] data;
    }
private:
    int head = 0;
    int tail = 0;
    int *data;
};
