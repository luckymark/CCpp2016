class Queue
{
public:
	void attend(int item);
	int pop();
	bool isEmpty();
	bool isFull();
private:
	int data[100];
	int head = 0;
	int tail = 0;
};
