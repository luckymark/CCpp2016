#pragma once
#define MAX 100
class Queue
{
private:
	int data[MAX];
	int head = 0;
	int tail = 0;
public:
	void append(int item);
	bool isEmpty();
	bool isFull();
	int pop();
};