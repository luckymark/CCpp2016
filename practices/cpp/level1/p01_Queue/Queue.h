#pragma once
#ifndef Queue
class Queue
{
public:
	void append();
	int pop();
	bool isEmpty();
	bool isFull();
private:
	int data[100];
	int head = 0;
	int tail = 0;

};

#endif // !Queue

