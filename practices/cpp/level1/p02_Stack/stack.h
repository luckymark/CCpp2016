class Stack {
public:
	Stack(int x = 100);
	int pop();
	int push(int item);
	bool isEmpty();
	bool isFull();
private:
	int data[100];
	int head = 0;
	int tail = 0;
	int quantity;
};