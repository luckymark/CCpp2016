#pragma once
#pragma once
#include <iostream>
class Stack {

public:
	Stack(int cap);
	~Stack();
	bool isEmpty();
	int pop();
	void append(int num);
	bool isFull();
private:
	int size, length;
	struct node
	{
		int data;
		node *next;
	};
	node *head = NULL, *p, *q = NULL, *t = NULL;
};