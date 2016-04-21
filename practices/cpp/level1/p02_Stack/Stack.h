#pragma once
#pragma once
#include <iostream>
class Stack {

public:
	Stack();
	~Stack();
	bool isEmpty();
	int pop();
	void append(int num);
private:
	struct node
	{
		int data;
		node *next;
	};
	node *head = NULL, *p, *q = NULL, *t = NULL;
};