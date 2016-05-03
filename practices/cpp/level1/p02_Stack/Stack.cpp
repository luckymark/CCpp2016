#include "Stack.h"
#include <iostream>
using namespace std;
Stack::Stack(int cap)
{
	this->size = cap;
	length = 0;
}

Stack::~Stack() {
	std::cout << "cleaning up";
}

bool Stack::isEmpty() {
	if (head->data == NULL) {
		return true;
	}
	else return false;
}

int Stack::pop() {
	p = head;
	do {
		q = p;
		if (p->next == NULL) break;
		p = p->next;
	} while (p->next != NULL);
	int pop = p->data;
	if (p != head) {
		q->next = NULL;
		delete p;
	}
	else {
		p->data = NULL;
	}
	length--;
	return pop;
}

void Stack::append(int num) {
	p = new node;
	p->data = num;
	p->next = NULL;
	if (head == NULL) {
		head = p;
	}
	else {
		q->next = p;
	}
	q = p;
	length++;
}

bool Stack::isFull() {
	return (length == size);
}