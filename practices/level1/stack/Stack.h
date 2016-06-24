#pragma once
class Stack
{
public:
	bool isFull(void);
	bool isEmpty(void);
	void push(int n);
	void pop(void);

private:
	int now= 0;
	int data[100];

};

