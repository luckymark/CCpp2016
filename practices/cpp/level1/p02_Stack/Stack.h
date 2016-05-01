#pragma once
#ifndef Stack
class Stack
{
public:
	Stack(int size);
	~Stack();
	void append();
	void pop();
	bool isEmpty();
	bool isFull();
private:
	int *data;
	int tail = 0;
	int dataSize;
};
#endif // !Stack
