#pragma once
class Stack
{
private:
	int *data;
	int head ;
public:
	Stack(int n, int head);
	void push(int n);
	int pop();
	bool isEmpty();
	bool isFull(int n);
	~Stack();
};