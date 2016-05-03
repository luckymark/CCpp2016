class Queue {
public:
    bool is_full();
    bool is_empty();
    int pop();
    void append(int n);

private:
    int head = 0;
    int tail = 0;
    int data[101];
};
