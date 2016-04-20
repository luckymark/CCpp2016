class Stack {
public:
    Stack(int num) {
	data = new int[num];
	tail = num;
    }
    ~Stack() {
    	delete[]data;
    }
	void push(int item);
	int pop();
	bool isFull(int num);
	bool isEmpty();
private:
    int head = 0;
    int tail;
    int *data;
};

